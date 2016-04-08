/*
Author：蔡宜勳 B033040009
Date：Nov. 2, 2015
Purpose:西洋棋騎士(knight)走完棋盤的順序
*/

#include <iostream>
#define STACK_MAX 2500
using namespace std;

class Stack {

    private:
        int i[STACK_MAX];
        int j[STACK_MAX];
        int direction[STACK_MAX];
        int now;

    public:
        Stack() {       // Constructor
            now = 0;
            for(int k = 0 ; k < STACK_MAX ; ++k){
            	i[k] = 0;
            	j[k] = 0;
            	direction[k] = 0;
            }
        }

        ~Stack(){}        // Destructor
		
		
		
        bool IsEmpty(){
            if(now == 0)
                return true;
            else
                return false;
        }

        int Top_i() {
            if (now == 0) {
                cout << "Error: stack empty" << endl;
                return -1;
            }
            return i[now];
        }

        int Top_j() {
            if (now == 0) {
                cout << "Error: stack empty" << endl;
                return -1;
            }
            return j[now];
        }

        int Top_direction() {
            if (now == 0) {
                cout << "Error: stack empty" << endl;
                return -1;
            }
            return direction[now];
        }



        void Push(int _i, int _j, int _direction) {
            if (now < STACK_MAX){
                now++;
                i[now] = _i;
                j[now] = _j;
                direction[now] = _direction;
            }
            else
                cout << "Error: stack full\n" << endl;
        }


        void Pop() {
            if (now == 0)
                cout << "Error: stack empty" << endl;
            else{
            i[now] = 0;
            j[now] = 0;
            direction[now] = 0;
            now--;
			}
                
        }
};

int main()
{
    int n;

    int ki[9] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
    int kj[9] = {0, 1, 2, 2, 1, -1, -2, -2, -1};


    while(cin >> n){
        int chessboard[51][51];
        for(int x = 0 ; x <= 51 ; ++x)
            for(int y = 0 ; y <= 51 ; ++y)
            chessboard[x][y] = 0;

        int now_pos_i = 1, now_pos_j = 1, now_step = 1;
        Stack st;
        chessboard[now_pos_i][now_pos_j] = now_step;

        if(n >= 3){
        st.Push(now_pos_i, now_pos_j, 3);
        now_pos_i += ki[3];
        now_pos_j += kj[3];
        }

        else if(n == 2)
                cout << "no solution" << endl;
        else if(n == 1)
                cout << "1" << endl;
        else
            cout << "no solution" << endl;

        int k = 1;

        if(n >= 3){

            while(st.IsEmpty() != true &&  now_step != n * n){

                while(  (now_pos_i + ki[k] < 1 || now_pos_i + ki[k] > n || now_pos_j + kj[k] < 1 || now_pos_j + kj[k] > n)    //下一步在棋盤外
                           || (chessboard[now_pos_i + ki[k]][now_pos_j + kj[k]] != 0) ){                                      //或是下一步的位置已經走過
                   
				    if(k == 8){
                    ++k;
                    break;
                    }
                   
                    else
                    ++k;
                }
                                                                                                                  
                if(k <= 8){
                    st.Push(now_pos_i, now_pos_j, k);
                    cout << "push" << now_pos_i << " " << now_pos_j << " "<< endl;
                    chessboard[now_pos_i][now_pos_j] = now_step;
                    now_pos_i += ki[k];
                    now_pos_j += kj[k];
                    now_step++;
                    
                    k = 1;
                }
                
                if(k == 9){                      //所有方向都嘗試過 無路可走
                	cout << "pop " << now_step << endl;
                    chessboard[now_pos_i][now_pos_j] = 0;
                    now_step--;
                    now_pos_i = st.Top_i();
                    now_pos_j = st.Top_j();
                    k = st.Top_direction() + 1;
                    st.Pop();
                }
            }

            if(st.IsEmpty() == true)
                cout << "no solution" << endl;

            if(now_step == n*n){
                for (int x = 1 ; x <= n ; ++x){
                    for(int y = 1 ; y <= n ; ++ y)
                        cout << chessboard[x][y] << " ";
                    cout << endl;
                }
            }

        }
    }
}
