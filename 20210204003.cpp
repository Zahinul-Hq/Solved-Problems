#include<bits/stdc++.h>
using namespace std;

struct Task {
    string Name;
    int ArrivalTime, RemainingTime, InitialCpuTime,  EndTime, FirstResponseTime;
};

struct CompareTask {
    bool operator()(const Task& t1, const Task& t2) {
        if (t1.RemainingTime != t2.RemainingTime) {
            return t1.RemainingTime > t2.RemainingTime;
        }
        return t1.ArrivalTime > t2.ArrivalTime;
    }
};

bool compareTasks(Task a, Task b) {
    return a.Name < b.Name;
}
bool cmp_time(Task a, Task b) {
    return a.ArrivalTime < b.ArrivalTime;
}

int numTasks;
vector<Task> tasks, completedTasks;
priority_queue<Task, vector<Task>, CompareTask> activeQueue, tempQueue;
queue<pair<string, int>> ganttQueue;


void renderGanttChart() {
    vector<int> times;
    times.push_back(0);

    while (!ganttQueue.empty()) {
        string name = ganttQueue.front().first;
        int time = ganttQueue.front().second;
        while (!ganttQueue.empty() && ganttQueue.front().first == name) {
            time = ganttQueue.front().second;
            ganttQueue.pop();
        }
        times.push_back(time);
        cout << "| " << name << " |";
    }
    cout << endl;

    for (int i = 0; i < times.size(); i++) {
        cout << times[i] << "   ";
        if (i == 0) cout << " ";
    }
    cout << endl;
}

void displaySummary() {
    sort(completedTasks.begin(), completedTasks.end(), compareTasks);
    

    double avgTAT = 0, avgWT = 0, avgRT = 0;

    for (int i = 0; i < numTasks; i++) {
        int turnaroundTime = completedTasks[i].EndTime - completedTasks[i].ArrivalTime + 1;
        int waitingTime = turnaroundTime - completedTasks[i].InitialCpuTime;
        int responseTime = max(completedTasks[i].FirstResponseTime, 0) - completedTasks[i].ArrivalTime;
        avgTAT += turnaroundTime;
        avgWT += waitingTime;
        avgRT += responseTime;
    }

    cout << "Average Waiting Time: " << (avgWT / numTasks) << endl;
    cout << "Average Turnaround Time: " << (avgTAT / numTasks) << endl;
    cout << "Average Response Time: " << (avgRT / numTasks) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> numTasks;
    vector<string> names(numTasks);
    vector<int> arrivalTimes(numTasks), cpuTimes(numTasks), priorities(numTasks);

    for (int i = 0; i < numTasks; i++) {
        cin >> names[i];
    }
    for (int i = 0; i < numTasks; i++) {
        cin >> arrivalTimes[i];
    }
    for (int i = 0; i < numTasks; i++) {
        cin >> cpuTimes[i];
    }
    for (int i = 0; i < numTasks; i++) {
        
        tasks.push_back({names[i], arrivalTimes[i], cpuTimes[i], cpuTimes[i], 0, -1 });
    }

    int currentIndex = 0;
    activeQueue.push(tasks[currentIndex++]);

    Task currentTask;
    int  Curr_AT = 0;

    for (int time = 0; !activeQueue.empty(); time++) {
        currentTask = activeQueue.top();
        activeQueue.pop();

        ganttQueue.push({currentTask.Name, time});

        currentTask.RemainingTime--;

        if (currentTask.FirstResponseTime == -1) {
            currentTask.FirstResponseTime = time;
        }
        if (currentTask.RemainingTime == 0) {
            currentTask.EndTime = time;
            completedTasks.push_back(currentTask);
            while(currentIndex < numTasks && tasks[currentIndex].ArrivalTime <= time) {
                activeQueue.push(tasks[currentIndex++]);
            }

            continue;
        }

        activeQueue.push(currentTask);
    }

    renderGanttChart();
    displaySummary();

    return 0;
}
