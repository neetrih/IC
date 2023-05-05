#include <iostream>

#include <unordered_map>
#include "BinTree.h"
#include "Bitmap.h"
#include <string>
#include <queue>

using namespace std;


class HuffmanNode {
public:
	char wo;
	char ch; 
	int freq; // 出现频率
	HuffmanNode* left; // 左子节点
	HuffmanNode* right; // 右子节点
	
	// 构造函数
	HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
	~HuffmanNode();
};

struct Compare {
	bool operator()(const HuffmanNode* a, const HuffmanNode* b) const {
		return a->freq > b->freq;
	}
};
bool i=false;

HuffmanNode* buildHuffTree(const string& str) {
	
	unordered_map<char, int> freqMap;
	for (char c : str) {
		++freqMap[c];
	}
	
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
	for (auto& [c, freq] : freqMap) {
		pq.push(new HuffmanNode(c, freq));
	}
	
	while (pq.size() > 1) {
		HuffmanNode* left = pq.top();
		pq.pop();
		HuffmanNode* right = pq.top();
		pq.pop();
		HuffmanNode* parent = new HuffmanNode('\0', left->freq + right->freq);
		parent->left = left;
		parent->right = right;
		pq.push(parent);
	}
	
	return pq.top();
}



string huffmanEncode(const string& str, const unordered_map<char, string>& codeMap) {
	string encodedStr;
	encodedStr.reserve(str.size() * 2);
	for (char c : str) {
		auto it = codeMap.find(c);
		if (it == codeMap.end()) {
			continue; 
		}
		encodedStr.append(it->second);
	}
	return encodedStr;
}
void generateCodes(HuffmanNode* root, string code, unordered_map<char, string>& codeMap) {
	if (root == nullptr) {
		return;
	}
	if (!root->left && !root->right) {
		codeMap[root->ch] = code;
		return;
	}
	generateCodes(root->left, code + " 0", codeMap);
	generateCodes(root->right, code + " 1", codeMap);
}
int main() {

	string str = "I have a dream today!	I have a dream that one day, down in Alabama, with its vicious racists, with its governor having his lips dripping with the words of interposition and nullification- one day right there in Alabama little black boys and black girls will be able to join hands with little white boys and white girls as sisters and brothers.	I have a dream today!	I have a dream that one day every valley shall be exalted, and every hill and mountain shall be made low, the rough places will be made plain, and the crooked places will be made straight; and the glory of the Lord shall be revealed and all flesh shall see it together.2	This is our hope, and this is the faith that I go back to the South with.	With this faith, we will be able to hew out of the mountain of despair a stone of hope. With this faith, we will be able to transform the jangling discords of our nation into a beautiful symphony of brotherhood. With this faith, we will be able to work together, to pray together, to struggle together, to go to jail together, to stand up for freedom together, knowing that we will be free one day.	And this will be the day -- this will be the day when all of God's children will be able to sing with new meaning:		My country 'tis of thee, sweet land of liberty, of thee I sing. Land where my fathers died, land of the Pilgrim's pride, From every mountainside, let freedom ring!	And if America is to be a great nation, this must become true		And so let freedom ring from the prodigious hilltops of New Hampshire.	Let freedom ring from the mighty mountains of New York.Let freedom ring from the heightening Alleghenies of Pennsylvania.		Let freedom ring from the snow-capped Rockies of Colorado.		Let freedom ring from the curvaceous slopes of California.		But not only that:	Let freedom ring from Stone Mountain of Georgia.	Let freedom ring from Lookout Mountain of Tennessee.		Let freedom ring from every hill and molehill of Mississippi.	From every mountainside, let freedom ring	And when this happens, and when we allow freedom ring, when we let it ring from every village and every hamlet, from every state and every city, we will be able to speed up that day when all of God's children, black men and white men, Jews and Gentiles, Protestants and Catholics, will be able to join hands and sing in the words of the old Negro spiritual:	Free at last! Free at last!	Thank God Almighty, we are free at last!";
	HuffmanNode* root = buildHuffTree(str);
	
	
	unordered_map<char, string> codeMap;
	generateCodes(root, "", codeMap);
	
	// 对dream进行编码
	string dreamCode = codeMap['d'] + codeMap['r'] + codeMap['e'] + codeMap['a'] + codeMap['m'];
	cout << "the code of dream is:" << dreamCode << endl;
	
	// 对equal进行编码
	string equalCode = codeMap['f'] + codeMap['u'] + codeMap['c'] + codeMap['k'] + codeMap['!'];
	cout << " the code of pentiment is：" << equalCode << endl;
	
	// Huffman编码
	string encodedStr = huffmanEncode(str, codeMap);
	cout << "the article encoded by Huffman is：" <<endl<< encodedStr << endl;
	
	return 0;	
}
