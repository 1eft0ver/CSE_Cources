#include "mytar.h"

tarfile::tarfile()
{
  filename[0] = '\0';
}

tarfile::tarfile( const char *tarFileName ) {
  file.open( tarFileName, ios::in | ios::binary );
  if (!file.good()) {
    cout << "openfile failed";
    filename[0] = '\0';
  }
  else {
    strcpy( this->filename, tarFileName );
    filename[strlen( tarFileName )] = '\0';
  }
  this->close();
}

tarfile::~tarfile() {
  this->close();
}

void tarfile::openfile() {
  file.open( filename, ios::in | ios::binary );
  file.seekg( 0, file.end );
  this->tar_total_bytes = file.tellg();
  file.seekg( 0, file.beg );
}

void tarfile::check_format() {
  char check_buffer[512];
  char checksum[8];
  file.read( check_buffer, 512 );
  file.seekg( 0 );

//Checksum CHECK
  for ( int i = 148; i < 156; i++ ){
    checksum[i - 148] = check_buffer[i];  //copy checksum field to checksum[]
    check_buffer[i] = ' ';                //set the checksum field to zero
  }

//check both signed and unsigned sum
  int signedSum = 0;
  int unsignedSum = 0;
  for ( int i = 0; i < 512; i++ ) {
    unsignedSum += check_buffer[i];
    signedSum += check_buffer[i];
  }

  for ( int i = 148; i < 156; i++ )
    check_buffer[i] = checksum[i - 148];  //copy back the checksum field

  long long int referenceChecksum = OctToDec(checksum);
  if(referenceChecksum != unsignedSum || referenceChecksum != signedSum) {
    cout << "checksum incorrect.\nchecksum: " << referenceChecksum << "\nunsignedChecksum: " << unsignedSum << "\nsignedChecksum: " << signedSum << endl;
    cout << "Not a ustar file.\nFile opening error." << endl;
    this->close();
    exit( EXIT_SUCCESS );
  }

  if ( this->tar_total_bytes < 512 ) {
    cout << "tar_total_bytes:" << tar_total_bytes << " bytes, not a tarfile" << endl;
    this->close();
    exit( EXIT_SUCCESS );
  }

//USTAR FILE CHECK
  char ustar_check[6];
  file.seekg( 257 );
  file.read( ustar_check, 5 );
  ustar_check[5] = '\0';
  file.seekg( 0, file.beg );
  if ( strcmp( ustar_check, "ustar" ) != 0 ) {
    cout << "Not a ustar file.\nFile opening error." << endl;
    this->close();
    exit( EXIT_SUCCESS );
  }
}

void tarfile::encoding() {
  while (1) {
    int temp = check_header();
    file.seekg( temp, ios::cur );
    tar_total_bytes -= temp;

    if ( tar_total_bytes < 0 )
      break;
  }
}

int tarfile::check_header()
{
  char buffer[512];
  file.read( buffer, 512 );
  TarHeader tar_header;

  //Field filename
  for ( int i = 0; i < 100; i++ ) {
    if ( isprint( buffer[i] ) )
      tar_header.filename[i] = buffer[i];

    else
      tar_header.filename[i] = '\0';
  }

  //Field filemode
  for ( int i = 100; i < 108; i++ ) {
    if ( isdigit( buffer[i] ) )
      tar_header.filemode[i - 100] = buffer[i];

    else
      tar_header.filemode[i - 100] = '\0';
  }

  //Field filesize
  for ( int i = 124; i < 135; i++ ) {
    if ( isprint( buffer[i] ) )
      tar_header.filesize[i - 124] = buffer[i];
  }
  tar_header.filesize[12] = '\0';

  //Filed mtime
  //Last modification time in numeric Unix time format (octal)
  for ( int i = 136; i < 148; i++ ) {
    if ( isdigit( buffer[i] ) )
      tar_header.mtime[i - 136] = buffer[i];

    else
      tar_header.mtime[i - 136] = '\0';
  }

  //Field username
  //Owner user name
  for ( int i = 265; i < 297; i++ ) {
    if ( isprint( buffer[i] ) )
      tar_header.username[i - 265] = buffer[i];

    else
      tar_header.username[i - 265] = '\0';
  }

  //Field groupname
  //Owner group name
  for ( int i = 297; i < 329; i++ ) {
    if ( isprint( buffer[i] ) )
      tar_header.groupname[i - 297] = buffer[i];

    else
      tar_header.groupname[i - 297] = '\0';
  }

  //Link indicator (file type)
  //'0' or ASCII NUL : Normal file
  //'1' : Hard link
  //'2' : Symbolic link
  tar_header.type = buffer[156];

  if ( strlen( tar_header.filename ) == 0 ) //jump trash block
    return 512;

  int tempsize = OctToDec(tar_header.filesize);
  tar_header.size = tempsize;

  time_t raw_time = strtol( tar_header.mtime, NULL, 8 );
  strcpy( tar_header.time_str, ctime( &raw_time ) );
  tar_header.time_str[strlen( tar_header.time_str ) - 1] = '\0';
  databuffer.push_back( tar_header );

  if ( tempsize % 512 == 0 )
    return tempsize;
  else
    return ( tempsize / 512 ) * 512 + 512;
}

void tarfile::print_result() {
  char permisson[][8] = {"---", "--x", "--w", "-wx", "r--", "r-x", "rw-", "rwx"};
  cout << "total " << databuffer.size() << " files" << endl;
  for ( unsigned int i = 0; i < databuffer.size(); i++ ) {
    if ( databuffer[i].type == '5' )
      cout << "d";
    else
      cout << "-";

    for ( unsigned int j = strlen( databuffer[i].filemode ) - 3; j < strlen( databuffer[i].filemode ); j++ )
      cout << permisson[databuffer[i].filemode[j] - '0'];

    cout << "  ";
    cout << left << setw( 15 ) << databuffer[i].username;
    cout << left << setw( 15 ) << databuffer[i].groupname;
    cout << right << setw( 8 ) << databuffer[i].size;
    //cout << right << setw( 26 ) << databuffer[i].time_str;
    cout << "  " << left << setw( 20 ) << databuffer[i].filename;
    cout << endl;
  }
}


void tarfile::close() {
  file.close();
}

int main( int argc, const char *argv[] ) {
  tarfile tar_obj( argv[1] );
  tar_obj.openfile();
  tar_obj.check_format();
  tar_obj.encoding();
  tar_obj.print_result();
  tar_obj.close();
  return 0;
}
