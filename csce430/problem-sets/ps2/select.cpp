#include <iostream>
#include <sstream>

#include <unordered_map>
#include <set>
#include <stack>

#include <string>

using namespace std;

int main() {
    unordered_map<string,set<string>> um;
    string line;

    while (getline(cin,line)) {
        istringstream iss(line);
        string op;
        while(iss >> op) {
            if (op == "group") {
                string name, person;
                int n;

                iss >> name >> n;
                set<string> s;
                for(int i = 0; i < n; i++) {
                    iss >> person;
                    s.insert(person);
                }
                um.emplace(name,s);
            }
            else {
                stack<string> stack_ops;
                stack<set<string>> stack_groups;
                
                stack_ops.push(op);
                
                string next;
                while (iss >> next) {
                    // group
                    if (um.count(next) > 0)
                        stack_groups.push(um.at(next));
                    // operation
                    else
                        stack_ops.push(next);
                }
                
                set<string> ss1,ss2;
                while(stack_ops.size() != 0) {
                    op = stack_ops.top();
                    stack_ops.pop();
                    
                    ss1 = stack_groups.top();
                    stack_groups.pop();
                    
                    ss2 = stack_groups.top();
                    stack_groups.pop();

                    set<string>::iterator ssit;
                    if (op == "union") {
                        for(ssit = ss1.begin(); ssit != ss1.end(); ssit++)
                            ss2.insert(*ssit);
                        stack_groups.push(ss2);
                    }
                    else if (op == "intersection") {
                        set<string> ss_intersect;
                        for(ssit = ss1.begin(); ssit != ss1.end(); ssit++) {
                            if (ss2.count(*ssit) > 0)
                                ss_intersect.insert(*ssit);
                        }
                        stack_groups.push(ss_intersect);
                    }
                    else if (op == "difference") {
                        set<string> ss_diff;
                        for(ssit = ss2.begin(); ssit != ss2.end(); ssit++) {
                            if (ss1.count(*ssit) == 0)
                                ss_diff.insert(*ssit);
                        }
                        stack_groups.push(ss_diff);
                    }
                }
                set<string> sg = stack_groups.top();
                set<string>::iterator sgit;
                for(sgit = sg.begin(); sgit != sg.end(); sgit++)
                    cout << *sgit << " ";
                cout << endl;
            }
        }
    }

    return 0;
}