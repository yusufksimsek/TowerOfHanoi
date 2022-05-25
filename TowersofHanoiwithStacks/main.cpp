#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int disk_To(stack<int>& m,stack<int>& n){
    if(n.empty()==true){
        n.push(m.top());
        m.pop();
        return 1;
    }
    else if(m.empty()==true){
        m.push(n.top());
        n.pop();
        return 2;
    }
    else{
        if(n.top()>m.top()){
            n.push(m.top());
            m.pop();
            return 1;
        }
        else{
            m.push(n.top());
            n.pop();
            return 2;
        }
    }
}

int main()
{
    
    stack<int> s,a,d;
    int number_of_disks=0;
    cout<<"Please enter how many disks are you going to use?"<<endl;
    cin>>number_of_disks;
    for(int i=number_of_disks;i>=1;i--){
        s.push(i);
    }
    
    cout<<"----------------------"<<endl;
    
    int x=pow(2,number_of_disks)-1;
    int i=1;
        
if(number_of_disks%2==0){
    while(i<=x){
            if(i%3==1){
            int y=disk_To(s,a);
            if(y==1){
                cout<<a.top()<<endl;
            }
            else
                cout<<s.top()<<endl;
            }
            else if(i%3==2){
            int y=disk_To(s,d);
            if(y==1){
                cout<<d.top()<<endl;
            }
            else
                cout<<s.top()<<endl;
            }
            else{
            int y=disk_To(a,d);
            if(y==1){
                cout<<d.top()<<endl;
            }
            else
                cout<<a.top()<<endl;
            }
            i++;
    }
}
else{
    while(i<=x){
            if(i%3==1){
            int y=disk_To(s,d);
            if(y==1){
                cout<<d.top()<<endl;
            }
            else
                cout<<s.top()<<endl;
            }
            else if(i%3==2){
            int y=disk_To(s,a);
            if(y==1){
                cout<<a.top()<<endl;
            }
            else
                cout<<s.top()<<endl;
            }
            else{
            int y=disk_To(a,d);
            if(y==1){
                cout<<d.top()<<endl;
            }
            else
                cout<<a.top()<<endl;
            }
            i++;
    }
}

cout<<"---------------------------"<<endl;
    
while(d.empty()!=true){
        cout<<d.top()<<endl;
        d.pop();
    }
    
    return 0;
}
