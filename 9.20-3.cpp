#include <iostream>
#include <cstdlib>
using namespace std;
struct 链表{
    int 数据;
    链表 *下一个;
    链表 *上一个;
};
struct 栈{
    链表 *头部 = nullptr;
};
struct 队列{
    链表 *头部 = nullptr;
    链表 *尾部 = nullptr ;
};
void push(栈 &s,int x){
    链表 *p = new 链表;
    (*p).数据 =x;
    (*p).下一个 =s.头部;
    p->上一个 = nullptr;
    if (s.头部 != nullptr) {
        s.头部->上一个 = p;
    }
    s.头部 =p;
}
int pop(栈 &s){
    if(s.头部 == nullptr){
        cout<<"无值"<<endl;
        return 0;
    }
    链表 *p = s.头部;
    int 暂存 = p->数据;
    s.头部 = p->下一个;
    if(s.头部 !=nullptr){
        s.头部->上一个 =nullptr;
    }
    delete p;
    return 暂存;
}
void 入队(队列 &d,int y){
    链表 *p = new 链表;
    p->数据=y;
    p->下一个 = nullptr;
    p->上一个 = nullptr;
    if(d.尾部 == nullptr){
        d.尾部 = p;
        d.头部 = p;
    }else{
        d.尾部->下一个 = p;
        p->上一个 = d.尾部;
        d.尾部 = p;
    }
}
int 出队(队列 &d){
    if(d.头部 == nullptr){
        cout<<"无值"<<endl;
        return 0;
    }
    链表 *p = d.头部;
    int 暂存 = p->数据;
    d.头部 = p->下一个;
    if(d.头部 != nullptr){
        d.头部->上一个 = nullptr;
    }else{
        d.尾部 = nullptr;
    }
    delete p;
    return 暂存;
}
void 遍历(链表 *头部){
    链表 *p= 头部;
    while(p !=nullptr){
        cout<<p->数据<<" ";
        p = p->下一个;
    }
    cout<<endl;
}
链表 *删除链表(链表 *头部,int a){
    链表 *p = 头部;
    while (p !=nullptr&&p->数据 !=a){
        p = p->下一个;
    }
        if(p==nullptr){
            return 头部;
        }
        if(p->上一个!=nullptr){
            p->上一个->下一个=p->下一个;
        }else{
            头部=p->下一个;
        }
        if(p->下一个!=nullptr){
            p->下一个->上一个=p->上一个;
        }
    delete p;
    return 头部;
}
链表 *插入链表(链表 *头部,int b){
    链表 *p = new 链表;
    p->数据=b;
    p->上一个 = nullptr;
    p->下一个 = 头部;
    if(头部 !=nullptr){
        头部->上一个=p;
    }
    头部 = p;
    return 头部;  
}
int main(){
    system("chcp 65001");
    栈 s;
    队列 d;
    链表 *头 = nullptr;
    int 选择;
    while (true){
        cout<<"==主菜单=="<<endl;
        cout<<"1.链表"<<endl;
        cout<<"2.队列"<<endl;
        cout<<"3.栈"<<endl;
        cout<<"4.退出"<<endl;
        cin>>选择;
        if(选择==1){
            int 子选择;
            int 数字;
            while(true){
            cout<<"链表菜单"<<endl;
            cout<<"1.遍历,2.头插,3.删除,4.返回"<<endl;
            cin>>子选择;
                if(子选择==1){
                    遍历(头);
                }
                else if(子选择==2){
                    cout<<"请输入数字"<<endl;
                    cin>>数字;
                    头 = 插入链表(头,数字);
                }
                else if(子选择==3){
                    cout<<"请输入要删除的数字"<<endl;
                    cin>>数字;
                    头 = 删除链表(头,数字);
                }
                else if(子选择==4){
                    break;
                }
                else {
                cout << "输入错误，请重新选择" << endl;
                } 
            }
        }
        else if(选择==2){
            int 子选择;
            int 数字;
            while(true){
            cout<<"队列菜单"<<endl;
            cout<<"1.入队,2.出队,3.返回"<<endl;
            cin>>子选择;
                if(子选择==1){
                    cout<<"请输入数字"<<endl;
                    cin>>数字;
                    入队(d,数字);
                }
                else if(子选择==2){
                    cout<<出队(d)<<endl;
                }
                else if(子选择==3){
                    break;
                }
                else {
                cout << "输入错误，请重新选择" << endl;
                } 
            }
        }
        else if(选择==3){
            int 子选择;
            int 数字;
            while(true){
            cout<< "栈菜单"<<endl;
            cout<<"1.压入,2.弹出,3.返回,"<<endl;
            cin>>子选择;
                if(子选择==1){
                    cout<<"请输入数字"<<endl;
                    cin>>数字;
                    push(s,数字);
                }
                else if(子选择==2){
                    cout<<pop(s)<<endl;
                }
                else if(子选择==3){
                    break;
                }
                else {
                cout << "输入错误，请重新选择" << endl;
                } 
            }
        }
        else if(选择==4){
            break;
        }
       else {
                cout << "输入错误，请重新选择" << endl;
                } 
         }
    return 0;
}
