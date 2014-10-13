//
//  main.cpp
//  pro1
//
//  Created by el1ven on 14-6-6.
//  Copyright (c) 2014年 el1ven. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>

using namespace std;

//关于栈混洗的检测

int main()
{
    stack<int> s,a,b;
    int n = 0;
    while(cin>>n){
        for(int i = 1; i <= n; i++){
            a.push(n-i+1);//初始化输入序列1,2,3,4,5
        }
        for(int j = 0; j < n; j++){
            int num = 0;
            cin>>num;
            b.push(num);
            //输入需要检测的序列1,4,5,2,3; 由于栈是倒着显示的，所以我们需要输入3,2,5,4,1,最后的结果是NO
        }
        for(int k = 0; k < n; k++){//对于b中的序列进行循环迭代
            
            if(!a.empty()){//先把a中的一个元素压栈, 需要判断a是否为空
                s.push(a.top());
                a.pop();
            }
            
            if(b.top() == s.top()){//如果他们相等就消去
                b.pop();
                s.pop();
            }else{//如果不相等就一直压栈直到他们相等可以消去
                int flag = b.top();
                while(!a.empty() && flag != a.top()){
                    s.push(a.top());
                    a.pop();
                }
            }
        }
        
        
        if(s.top() == b.top())//最终栈中会剩余元素，如果栈顶元素等于b的尾元素就证明YES的结果
            cout<<"YES,小表砸"<<endl;
        else
            cout<<"NO,小表砸"<<endl;
    }

    return 0;
}























