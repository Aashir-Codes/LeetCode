class Solution {
public:
int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
    stack<int> sand;

    for (int i = sandwiches.size() - 1; i >= 0; i--) {
        sand.push(sandwiches[i]);
    }

    int rotations = 0;
    while (!students.empty() && !sand.empty()) {
        if (students.front() == sand.top()) {

            students.erase(students.begin());
            sand.pop();
            rotations = 0;
        }
        else {

            int front = students.front();
            students.erase(students.begin());
            students.push_back(front);
            rotations++;

            if (rotations == students.size()) {
                break;
            }
        }
    }
    return students.size();
}
};