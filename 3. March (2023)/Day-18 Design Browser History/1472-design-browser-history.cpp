//* https://leetcode.com/problems/design-browser-history/
//* https://leetcode.com/problems/design-browser-history/editorial/
//* https://www.youtube.com/watch?v=W2hhdHsGOUM&t=276s&ab_channel=CodeFreaks

class BrowserHistory {
    stack<string> history, future;
    string current;
public:
    BrowserHistory(string homepage) {
        // 'homepage' is the first visited URL.
        current = homepage;
    }

    void visit(string url) {
        // Push 'current' in 'history' stack and mark 'url' as 'current'.
        history.push(current);
        current = url;
        // We need to delete all entries from 'future' stack.
        future = stack<string>();
    }
    
    string back(int steps) {
        // Pop elements from 'history' stack, and push elements in 'future' stack.
        while(steps > 0 && !history.empty()) {
            future.push(current);
            current = history.top();
            history.pop();
            steps--;
        }
        return current;
    }
    
    string forward(int steps) {
        // Pop elements from 'future' stack, and push elements in 'history' stack.
        while(steps > 0 && !future.empty()) {
            history.push(current);
            current = future.top();
            future.pop();
            steps--;
        }
        return current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */