/* Program to schedule processes using Round Robin algorithm (without arrival time)
   Author : Dovahkiin
*/

#include<iostream>
using namespace std;

struct x{
int exec;
int last;
};

int main() {
int p,bt[100],dup[100],ts,i,j,k,temp,sum=0,index=0,store[10]={0};
int wt[100],tat[100];
cout<<"Enter number of processes : ";
cin>>p;
x process[10]={0};
cout<<"Enter the time slice : ";
cin>>ts;
cout<<"Enter the burst times of the proceses\n";
for(i=0;i<p;i++) {
        cin>>bt[i];
        dup[i]=bt[i];
        sum+=bt[i];
}cout<<endl;
cout<<"Grantt Chart"<<endl<<endl;
for(j=0; index!=sum;j++) {
        j=j%ts;
        if(dup[j] ==0) {
        continue;
}
        else if((dup[j]-ts)>=0) {
        process[j].last=index;
        index+=ts;
        dup[j]-=ts;
        process[j].exec+=store[j];
        store[j]=ts;
        cout<<"[P"<<j+1<<"]\t";
}
else {
        process[j].last=index;
        index+=dup[j];
        process[j].exec+=store[j];
        store[j]=dup[j];
        dup[j]=0;
        cout<<"[P"<<j+1<<"]\t";
}
}
cout<<endl<<endl;
cout<<"PROCESS          WAITING TIME            TURNAROUNDTIME"<<endl;
for(i=0;i<p;i++) {
        wt[i]=process[i].last-process[i].exec;
        tat[i]=wt[i]+bt[i];
        cout<<"P"<<i+1<<"               "<<wt[i]<<"                     "<<tat[i]<<endl;
}
}

