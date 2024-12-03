#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> m;

    pair<string,int> p=make_pair("hello",3);
    m.insert(p);

    pair<string,int> pair2("hi",2);
    m.insert(pair2);

    m["yo"]=1;

    m["yo"]=5;

    cout<<"Value in 'hi': "<<m["hi"]<<endl;
    cout<<"Value in 'yo': "<<m.at("yo")<<endl;
    cout<<"Insertion of new element: "<<m["bye"]<<endl;
    cout<<"Value in 'bye': "<<m.at("bye")<<endl;
    cout<<"Size of Unordered Map: "<<m.size()<<endl;

    //if the string is present or not
    cout<<"Check whether the value is present or not: "<<m.count("bro")<<endl;
    cout<<"Check whether the value is present or not: "<<m.count("hi")<<endl;

    m.erase("yo");
    cout<<"Size of Unordered Map after erasing 'yo' element: "<<m.size()<<endl;

    cout<<"Printing all the elements of unordered-map: "<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"Printing all the elements of unordered-map using iterator: "<<endl; //unordered-map prints in the wap value is pushed in
    unordered_map<string,int> :: iterator it1=m.begin();
    while(it1!=m.end()){
        cout<<it1->first<<" "<<it1->second<<endl;
        it1++;
    }

    map<string,int> mp;
    mp["Luffy"]=1;
    mp["Zoro"]=2;
    mp["Sanji"]=3;
    cout<<"Printing all the elements of map using iterator: "<<endl; //map prints in alphabetic order
    map<string,int> :: iterator it2=mp.begin();
    while(it2!=mp.end()){
        cout<<it2->first<<" "<<it2->second<<endl;
        it2++;
    }
}