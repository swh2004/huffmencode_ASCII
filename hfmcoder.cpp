#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <fstream>
#include <iomanip>
using namespace std;

struct hfmtree{

    int frequency;
    char ch;
    hfmtree *left, *right;

};

hfmtree *structNode(char ch, int freq, hfmtree* left, hfmtree* right){

	hfmtree *node = new hfmtree();

	node->ch = ch;
	node->frequency = freq;
	node->left = left;
	node->right = right;

	return node;

}

bool my_compare(hfmtree *a, hfmtree *b){

    if(a->frequency != b->frequency){
        return(a->frequency<b->frequency);
    }

    else{
        return a->ch<b->ch;
    }

}

vector<hfmtree*> process_frequency(string text){

    vector<hfmtree*> hfms;
    unordered_map<char, int> freq;

	for (int i = 0; i < text.size(); ++i) {
        char ch = text[i];
        freq[ch]++;
    }

    for (unordered_map<char, int> :: iterator it = freq.begin(); it != freq.end(); ++it) {
        hfms.push_back(structNode(it->first, it->second, nullptr, nullptr));
    }

    sort(hfms.begin(), hfms.end(), my_compare);
    
    return hfms;

}

vector<hfmtree*> resort(vector<hfmtree*> vec){

    if(vec[0]->ch > vec[1]->ch){
        hfmtree *tem = vec[0];
        vec[0] = vec[1];
        vec[1] = tem;
    } 

    hfmtree *node = structNode(vec[0]->ch, vec[0]->frequency+vec[1]->frequency,vec[0],vec[1]);

    vec.erase(vec.begin(),vec.begin()+2);
    vec.push_back(node);

    sort(vec.begin(), vec.end(), my_compare);

    return vec;
}

hfmtree *build_tree(vector<hfmtree*> vec){

    int l=vec.size();

    while(l!=1){
        vec=resort(vec);
        l=vec.size();
    }

    return vec[0];

}

void encode(hfmtree* root, string str, unordered_map<char, string> &huffmanCode)
{
	if (root == nullptr)
		return;

	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

int main(int argc, char* argv[]){

    string file_name = argv[1];
    

    ifstream fin;
    fin.open(file_name.c_str());
    if(fin.fail()){
        exit(1);
    }

    string strings;
    getline(fin,strings);

    fin.close();

    vector<char> chs;
    vector<hfmtree*> hfms;
    unordered_map<char, string> hfmcode;

    for (int i = 0; i < strings.size(); ++i) {
        char ch = strings[i];
        if(!count(chs.begin(),chs.end(),ch)){
            chs.push_back(ch);
        }
    }

    sort(chs.begin(),chs.end());
 
    hfms=process_frequency(strings);
    hfmtree *root;
    root=build_tree(hfms);
    
    encode(root, "", hfmcode);

    ofstream file1,file2;
    file1.open("code.txt");
    file2.open("encodemsg.txt");

    if(file1.fail()){
        exit(1);
    }

    if(file2.fail()){
        exit(1);
    }

    double sum=0;

    for (int i = 0; i < strings.size(); ++i){
        char ch = strings[i];
        sum+=hfmcode[ch].size();
    }

    for (int i=0; i<chs.size(); ++i) {
        file1<<hfmcode[chs[i]]<<endl;  
    }
    file1<<setprecision(2)<<fixed<<sum/strings.size()<<endl;
    
    for (int i = 0; i < strings.size(); ++i){
        file2<<hfmcode[strings[i]];
    }

    file1.close();
    file2.close();

}
   
