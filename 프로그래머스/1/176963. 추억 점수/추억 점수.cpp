#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> m;
    
    //이름이랑 이름에 해당하는 점수 해시에 넣기
    for(int i=0;i<name.size();i++){
        m[name[i]] = yearning[i];
    }
    
    //문자열 벡터 하나를 받아옴. 해당 벡터는 각 사진에 들어가는 인물들
    for(auto& a:photo){
        int score=0;
        for(int i=0;i<a.size();i++){
            
            //해시맵에 내가 찾는 키가 존재하는지 검색할 때 find 메소드를 이용할 수 있다. -> find는 클래스 메소드임.
            //find의 결과는 이터레이터이므로 없으면 end임.
            if(m.find(a[i]) != m.end()){
                score += m[a[i]];
            }
        }
        
        answer.push_back(score);
    }
    return answer;
}