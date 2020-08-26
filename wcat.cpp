#include <iostream>

using namespace std;

int main (int argc, char * argv[]) {
    // cout << argv[1] << endl;
    FILE *temp; 
    char line[200];
    temp = fopen(argv[1],"r");
    if(temp==NULL){
        cout << "Cannot open file" << endl;
        exit(1);
    }
    cout << "Reading File" << endl;
    while(fgets (line,200,temp)!=NULL)
    cout << line << endl;
    cout << "Closing File" << endl;
    fclose(temp);


  return 0;   
}