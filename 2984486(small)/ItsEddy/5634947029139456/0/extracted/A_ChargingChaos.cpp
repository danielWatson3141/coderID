#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
void Try(vector<int> &SwitchCo,int Tr,vector<string> &Target,vector<string> &Origin,int &Min,int &SwitchCount,bool &Possible){
	if(Tr == SwitchCo.size())return;
	Try(SwitchCo,Tr + 1,Target,Origin,Min,SwitchCount,Possible);

	for(int d = 0;d < Origin.size();++d){
		if(Origin[d][SwitchCo[Tr]] == '0')
			Origin[d][SwitchCo[Tr]] = '1';
		else 
			Origin[d][SwitchCo[Tr]] = '0';
	}
	++SwitchCount;
	bool Possiblei = true;
	sort(Target.begin(),Target.end());
	sort(Origin.begin(),Origin.end());
	for(int i = 0;i < Origin.size();++i){
		if(Target[i] != Origin[i]){
			Possiblei = false;
			break;
		}
	}
	if(Possiblei){ 
		Possible = true;
		if(Min > SwitchCount)Min = SwitchCount;
	}
	Try(SwitchCo,Tr + 1,Target,Origin,Min,SwitchCount,Possible);
	for(int d = 0;d < Origin.size();++d){
		if(Origin[d][SwitchCo[Tr]] == '0')
			Origin[d][SwitchCo[Tr]] = '1';
		else 
			Origin[d][SwitchCo[Tr]] = '0';
	}
	--SwitchCount;
}
int main(){
	int TestCase,Case = 1;
	scanf("%d",&TestCase);
	while(TestCase--){
		int Device,Length;
		scanf("%d%d ",&Device,&Length);
		vector<int> OriginOnes(Length);
		vector<int> TargetOnes(Length);
		vector<string> Origin;
		vector<string> Target;
		vector<int> SwitchCo;
		int SwitchCount = 0;
		for(int i
				= 0;i < Device;++i){
			int ch,l=0;
			string temp(Length,'0');
			scanf(" ");
			while( ch = getchar() ){
				if(ch != '1' && ch != '0')break;
				if(ch == '1'){
					++OriginOnes[l];
					temp[l] = ch;
				}
				++l;
			}
			Origin.push_back(temp);
		}
		for(int i = 0;i < Device;++i){
			int ch,l=0;
			string temp(Length,'0');
			scanf(" ");
			while( ch = getchar() ){
				if(ch != '1' && ch != '0')break;
				if(ch == '1'){
					++TargetOnes[l];
					temp[l] = ch;
				}
				++l;
			}
			Target.push_back(temp);
		}

		bool Possible = true;
		for(int i = 0;i < Length;++i){
			if(TargetOnes[i] == OriginOnes[i]){
				if(TargetOnes[i] + OriginOnes[i] == Device)
					SwitchCo.push_back(i);
				continue;
			}
			else if(TargetOnes[i] + OriginOnes[i] == Device){
				for(int d = 0;d < Device;++d){
					if(Origin[d][i] == '0')
						Origin[d][i] = '1';
					else 
						Origin[d][i] = '0';
				}
				++SwitchCount;
				continue;
			}else{
				Possible = false;
				break;
			}
		}
		if(Possible){
			sort(Target.begin(),Target.end());
			sort(Origin.begin(),Origin.end());
			for(int i = 0;i < Device;++i){
				if(Target[i] != Origin[i]){
					Possible = false;
					break;
				}
			}
		}
		int Sw = SwitchCount;
		if(!Possible){
			SwitchCount = 99999999;
			 Try(SwitchCo,0,Target,Origin,SwitchCount,Sw,Possible);
		}
		if(Possible)
			printf("Case #%d: %d\n",Case++,SwitchCount,Sw);
		else
			printf("Case #%d: NOT POSSIBLE\n",Case++);
	}
	return 0;
}
