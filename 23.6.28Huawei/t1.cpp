
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.

#include <string>
#include <iostream>
using namespace std;
#define MAX_SIZE 10005

size_t getNext(char *in, size_t pos){
    while (in[pos] == ' ' || in[pos] == 'N'){
        pos++;
    }
    // if (in[pos] == '\0') return '\0';
    return pos;
}

size_t getPrev(char *in, size_t pos){
    while (in[pos] == ' ' || in[pos] == 'N'){
        pos--;
        if (pos == -1) return -1;
    }
    // if (in[pos] == '\0') return '\0';
    return pos;
}

int main()
{
    // please define the C++ input here. For example: int a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++ output here. For example:cout<<____<<endl;
    char in[MAX_SIZE];
    gets(in);
    // cout << in;

    size_t pos = 0;
    // size_t cur = pos;
    size_t next = getNext(in, pos + 1);
    while(in[next] != '\0'){
        switch (in[pos])
        {
        case 'L':
            if (in[next] == 'R'){
                in[pos] = 'N';
                in[next] = 'N';
                if ((pos = getPrev(in, pos)) == -1){
                    pos = next;
                }
            }
            else{
                pos = next;
            }
            break;
        case 'R':
            if (in[next] == 'L'){
                in[pos] = 'N';
                in[next] = 'N';
                if ((pos = getPrev(in, pos)) == -1){
                    pos = next;
                }
            }
            else{
                pos = next;
            }
            break;
        case 'U':
            if (in[next] == 'D'){
                in[pos] = 'N';
                in[next] = 'N';
                if ((pos = getPrev(in, pos)) == -1){
                    pos = next;
                }
            }
            else{
                pos = next;
            }
            break;
        case 'D':
            if (in[next] == 'U'){
                in[pos] = 'N';
                in[next] = 'N';
                if ((pos = getPrev(in, pos)) == -1){
                    pos = next;
                }
            }
            else{
                pos = next;
            }
            break;
        case 'F':
            if (in[next] == 'B'){
                in[pos] = 'N';
                in[next] = 'N';
                if ((pos = getPrev(in, pos)) == -1){
                    pos = next;
                }
            }
            else{
                pos = next;
            }
            break;
        case 'B':
            if (in[next] == 'F'){
                in[pos] = 'N';
                in[next] = 'N';
                if ((pos = getPrev(in, pos)) == -1){
                    pos = next;
                }
            }
            else{
                pos = next;
            }
            break;
        case 'N':
            pos = getNext(in, pos);
            break; 
        
        default:
            break;
        }
        if (in[pos] == '\0') break;
        // in[pos] = in[pos];
        next = getNext(in, pos + 1);
    }

    bool flag = true;
    pos = 0;
    char c = in[pos];
    if (c != ' ' && c != 'N'){
        cout << c;
        flag = false;
    }
    pos++;
    c = in[pos];
    while (c != '\0'){
        if (c != ' ' && c != 'N'){
            cout << " " << c;
            flag = false;
        }
        pos++;
        c = in[pos];
    }

    if (flag){
        cout << "N";
    }

    return 0;
}
