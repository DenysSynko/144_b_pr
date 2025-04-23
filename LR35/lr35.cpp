#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int countVowels(string word) {
    string vowels = "eyuioaEYUIOA";
    int k = 0, i, j;
    
    for (i = 0;i<word.length();i++) {
        for (j=0;j<vowels.length();j++) {
            if (word[i]==vowels[j]) {
                k++;
                break;
            }
        }
    }

    return k;
}

void copyWords(vector<string>& lines){
    int i, j;
    for (i=0;i<lines.size();i++){
        string line = lines[i];
        string word = "", newline = "";
        for (j=0;j<=line.length();j++) {
            char ch;
            if (j<line.length()) ch = line[j];
            else ch = ' ';
            if (ch != ' '){
                word += ch;
            }else{
                if(word != ""){
                    newline += word;
                    if (countVowels(word) > 2) newline += " " + word;
                    newline += " ";
                    word = "";
                }
            }
        }
        lines[i]=newline;
    }
}

int countIN(string text, string word){
    int count = 0;
    size_t pos = text.find(word, 0);
    while (pos != string::npos) {
        count++;
        pos = text.find(word, pos + word.length());
    }
    return count;
}

string delBetween(string& text, string& word) {
    size_t firstPos = text.find(word);
    size_t lastPos = text.rfind(word);

    if (firstPos != string::npos && lastPos != string::npos && firstPos != lastPos) {
        return text.substr(0, firstPos) + text.substr(lastPos + word.length());
    } else {
        return text;
    }
}

void ThreeLongest(vector<string>& lines, string longestWords[], int counts[]){
    int i, j;
    vector<string> words;
    for (i=0;i<lines.size();i++) {
        string word = "";
        for (j=0;j<=lines[i].length();j++) {
            char ch;
            if (j<lines[i].length()) ch = lines[i][j];
            else ch = ' ';
            if (ch != ' ' && ch != ',' && ch != '.' && ch != '?' && ch != '!'){
                word += ch;
            } else {
                if (word != "") {
                    bool found = false;
                    for (int k = 0; k < words.size(); k++) {
                        if (words[k] == word) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) words.push_back(word);
                    word = "";
                }
            }
        }
    }

    string top[3] = {"", "", ""};
    for (i=0;i<words.size();i++){
        if (words[i].length() > top[0].length()) {
            top[2] = top[1];
            top[1] = top[0];
            top[0] = words[i];
        } else if (words[i].length() > top[1].length() && words[i] != top[0]) {
            top[2] = top[1];
            top[1] = words[i];
        } else if (words[i].length() > top[2].length() && words[i] != top[0] && words[i] != top[1]) {
            top[2] = words[i];
        }
    }

    for (i = 0; i < 3; i++) {
        longestWords[i] = top[i];
        counts[i] = 0;
    }

    for (i = 0; i < lines.size(); i++) {
        string word = "";
        for (j = 0; j <= lines[i].length(); j++) {
            char ch;
            if (j<lines[i].length())ch=lines[i][j];
            else ch = ' ';
            if (ch != ' ' && ch != ',' && ch != '.' && ch != '?' && ch != '!') {
                word+=ch;
            } else {
                for (int k = 0; k < 3; k++) {
                    if(word == longestWords[k]) counts[k]++;
                }
                word="";
            }
        }
    }
}

vector<string> getSentences(string text, string word){
    vector<string> result;
    string sentence = "";
    for (int i = 0; i < text.length(); i++) {
        sentence += text[i];
        if (text[i]=='.' || text[i]=='?' || text[i]=='!') {
            if(sentence.find(word) != string::npos){
                result.push_back(sentence);
            }
            sentence = "";
        }
    }
    return result;
}

void searchWordInFile(string& word, const string& filePath) {
    ifstream in(filePath);
    string content((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());

    int count=countIN(content, word);

    if (count <= 1) {
        cout<<"Такого слова немає в рядку або зустрічається лише 1 раз.\n";
    } else {
        cout<<"Слово зустрічається "<<count<<" разів.\n";
        string modif=delBetween(content, word);
        ofstream filez3("z3.txt");
        filez3<<"Шукане слово: "<<word<<endl;
        filez3<<"Результат:\n"<<modif<<endl;
        filez3.close();
    }

    in.close();
}

void filesFors1s2s3(const string& tFilePath, const string& z1FilePath) {
    ifstream inZ1(z1FilePath);
    int wordCount = 0;
    string word;
    while (inZ1 >> word) {
        wordCount++;
    }
    inZ1.close();
    ifstream inT(tFilePath);
    vector<string> wordsFromT;
    while (wordsFromT.size() < wordCount && inT >> word) {
        wordsFromT.push_back(word);
    }
    inT.close();
    string s1;
    for (const string& w : wordsFromT) {
        s1 += w + " ";
    }
    string s2(s1);
    string s3 = s1 + s2;
    vector<string> allWords;
    string temp = "";
    for (char ch : s3) {
        if (ch == ' ') {
            if (!temp.empty()) {
                allWords.push_back(temp);
                temp = "";
            }
        } else {
            temp += ch;
        }
    }
    if (!temp.empty()) allWords.push_back(temp);
    sort(allWords.begin(), allWords.end());
    ofstream filez4("z4.txt");
    filez4<<"s1:\n" << s1 << "\n";
    filez4<<"s2:\n" << s2 << "\n";
    filez4<<"Відсортований s3:\n";
    for (const string& w : allWords) {
        filez4<<w<<" ";
    }
    filez4.close();
}

int main() {
    setlocale(LC_CTYPE, "ukr");
    vector<string> lines;
    string fulltext = "", temp;
    int i;
    ifstream filez1("z1.txt");
    while (getline(filez1, temp)) {
        lines.push_back(temp);
        fulltext += temp + " ";
    }
    filez1.close();
    vector<string> Copies = lines;
    string longestWords[3];
    int counts[3];
    vector<string> filtered;
    string searchWord, savePath;
    int p;
    bool m = true;

    while (m) {
        cout<<"|------------------------------------|"<<endl;
        cout<<"|----------------MENU----------------|"<<endl;
        cout<<"|1) Продублювати слова з 2+ голосних |"<<endl;
        cout<<"|2) Визначити 3 найдовших слова      |"<<endl;
        cout<<"|3) Вивести речення з заданим словом |"<<endl;
        cout<<"|4) Записати все у файл z2.txt       |"<<endl;
        cout<<"|5) Опрацювати слово в файлі         |"<<endl;
        cout<<"|6) Обробити s1, s2, s3              |"<<endl;
        cout<<"|7) EXIT                             |"<<endl;
        cout<<"|------------------------------------|"<<endl;
        cout<<">";
        cin>>p;
        cin.ignore();

        switch (p) {
            case 1:
                copyWords(Copies);
                break;
            case 2:
                ThreeLongest(lines, longestWords, counts);
                cout<<"Найдовші слова:\n";
                for (int i = 0; i < 3; i++) {
                    cout<<longestWords[i]<<" — "<<counts[i]<<endl;
                }
                break;
            case 3:
                cout<<"Введіть слово для пошуку: ";
                getline(cin, searchWord);
                filtered=getSentences(fulltext, searchWord);
                cout<<"Знайдені речення:\n";
                for(i = 0; i < filtered.size(); i++) {
                    cout<<filtered[i]<< endl;
                }
                break;
            case 4:
                cout<<"Введіть шлях до файлу для збереження:\n";
                getline(cin, savePath);
                {
                    ofstream filez2(savePath);
                    filez2<<"Пункт а):\n";
                    for(i=0;i<Copies.size();i++) filez2<<Copies[i]<<endl;
                    filez2<<"\nПункт б):\n";
                    for(i=0;i<3;i++) filez2<<longestWords[i]<<" — "<<counts[i]<<endl;
                    filez2<<"\nПункт в):\n";
                    for(i=0;i<filtered.size();i++) filez2<<filtered[i]<<endl;
                    filez2.close();
                }
                cout<<"Файл збережено."<<endl;
                break;
            case 5:
                cout<<"Введіть слово для обробки: ";
                getline(cin, searchWord);
                searchWordInFile(searchWord, "z1.txt");
                break;
            case 6:
                filesFors1s2s3("t.txt", "z1.txt");
                break;
            case 7:
                return 0;
        }
    }
}


