#include<bits/stdc++.h>
using namespace std;
struct Process{
	string Process_Name;
	int Arrival_Time, Cpu_Time, Curr_Priority , Priority, const_Cpu_Time, Finishing_Time, Response_Time ; 
};
struct CompareProcess {
    bool operator()(const Process& p1, const Process& p2) {
        if (p1.Cpu_Time != p2.Cpu_Time) {
            return p1.Cpu_Time > p2.Cpu_Time;
        }
        return p1.Arrival_Time > p2.Arrival_Time;
    }
};
bool cmp(Process a , Process b){
	return a.Process_Name < b.Process_Name;
}
int n;
int X, Y;
vector<Process>arr, answer;
priority_queue<Process, vector<Process>, CompareProcess>pq, temp_pq;
queue<pair<string,int>>QC;
void Gantt_Chart(){

	vector<int> T;
	T.push_back(0);

	while(!QC.empty()){
		string s = QC.front().first;
		int time = QC.front().second;
		while(QC.front().first == s){
			time = QC.front().second;
			QC.pop();
		}
		T.push_back(time);
		cout << "| " << s << " |"; 
	}
	cout << endl;


	for(int i = 0; i < T.size(); i++){
		cout << T[i] << "   ";
		if(i == 0) cout << " ";
	}
	cout << endl;



}
void Tabular_Form(){
	sort(answer.begin(), answer.end(),cmp);
	double AVG_TAT = 0, AVG_WT = 0, AVG_Response = 0;
	for(int i = 0; i < n; i++){
		int TAT = answer[i].Finishing_Time - answer[i].Arrival_Time + 1;
		int Waiting_time = TAT - answer[i].const_Cpu_Time ;
		int response_time = max(answer[i].Response_Time, 0) - answer[i].Arrival_Time;
		AVG_TAT += TAT;
		AVG_WT += Waiting_time;
		AVG_Response += response_time;
		
	}

	cout << "Average Waiting Time: " << (AVG_WT * 1.00) / n << endl;
	cout << "Average TurnAround Time: " << (AVG_TAT * 1.00) / n << endl;
	cout << "Average Response Time: " << (AVG_Response * 1.00) / n << endl;


}
void Input(){
	
	cin >> n;
	vector<string> Pname(n);
	vector<int> AT(n), CT(n), PT(n);
	// cout << "Enter Process Name" << endl;
	for(int i = 0; i < n; i++){
		cin >> Pname[i];
	}
	// cout << "Enter Arrival Time" << endl;
	for(int i = 0; i < n; i++){
		cin >> AT[i];
	}
	// cout << "Enter Cpu Time" << endl;
	for(int i = 0; i < n; i++){
		cin >> CT[i];
	}

	for(int i = 0; i < n; i++){
		Process pr;
		pr.Arrival_Time = AT[i];
		pr.Process_Name = Pname[i];
		pr.Cpu_Time = pr.const_Cpu_Time = CT[i];
		pr.Response_Time = -1;
		arr.push_back(pr);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

	Input();

	int i = 0;

	pq.push(arr[i++]);

	Process curr_process;

	for(int time = 0; !pq.empty(); time++){

		//Show_Priority_Values(time);
		if(i < n && arr[i].Arrival_Time == time){
			pq.push(arr[i++]);
		}

		curr_process = pq.top();
		pq.pop();

		QC.push({curr_process.Process_Name, time});

		curr_process.Cpu_Time--; 
		
		if(curr_process.Response_Time == -1){
			curr_process.Response_Time = time;
		}
		if(curr_process.Cpu_Time == 0){
			curr_process.Finishing_Time = time;
			answer.push_back(curr_process);
			continue;
		}

		pq.push(curr_process);

	}

	Gantt_Chart();
	Tabular_Form();

    return 0 ;

    

}
