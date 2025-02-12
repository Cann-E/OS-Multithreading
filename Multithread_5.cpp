#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include <pthread.h>
#include <unistd.h>

using namespace std;

struct arguments{
  int input;
  string output;
};


void* decrementEvens(void* arg_ptr){
  //dereference the arg_ptr
  

  //implement the answer to output

  return nullptr;
}

int main(){
  vector <int> nums;
  string strNum;

  cin >> strNum;

  for (int i=0; i<strNum.length(); i++){
    nums.push_back(strNum[i] - '0');
  }

  struct arguments args[nums.size()]; //set the size of args
  pthread_t tid[nums.size()]; //set the size of threads

  for (int i=0; i<nums.size(); i++){ //loop 4 times with the example of "1234"
    args[i].input = //set the inputs into individual argument
    pthread_create(&tid[i],nullptr,decrementEvens,&args[i]);//pthread_create here

  }

  //pthread_join here
  for(int i=0;i<nums.size();i++){
    pthread_join(tid[i],nullptr);
  }

  for (int i=0; i<nums.size(); i++){
    cout << args[i].output << " ";
  }
}