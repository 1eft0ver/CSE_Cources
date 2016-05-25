DROP TABLE IF EXISTS students;
CREATE TABLE students (
  id varchar(45) NOT NULL,
  sex varchar(45) NOT NULL,
  birthmonth int NOT NULL,
  PRIMARY KEY (id)
) ;

INSERT INTO students VALUES ('Akai','M',12),('Andy','M',6),('Annie','F',9),('Cookie','F',9),('Jim','M',8),('Judy','F',4),('Michael','M',9),('Mike','M',1),('Wolf','M',9),('Wei','M',6);
