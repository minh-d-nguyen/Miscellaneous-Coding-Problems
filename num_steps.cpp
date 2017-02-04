
/*
Problem: You are in an infinite 2D grid where you can move in any of 
the 8 directions :
    (x,y) to 
    (x+1, y), 
    (x - 1, y), 
    (x, y+1), 
    (x, y-1), 
    (x-1, y-1), 
    (x+1,y+1), 
    (x-1,y+1), 
    (x+1,y-1) 
You are given a sequence of points and the order in which you need to 
cover the points. Give the minimum number of steps in which you can 
achieve it. You start from the first point.

Solution approach: Count number of diagonal steps + vertical/horizontal
steps

Solution time complexity: O(n)
*/
int distance(int x1, int y1, int x2, int y2);

int num_steps(vector<int> &X, vector<int> &Y) {
    unsigned num_points = X.size();
    unsigned num_steps = 0;
    if (num_points <= 1) {
        return 0;
    }
    
    for (int i = 0; i < num_points - 1; i++) {
        if (i >= X.size() || i >= Y.size()) {
            return 0;
        }
        num_steps += distance(X[i], Y[i], X[i+1], Y[i+1]);
    }
    return num_steps;
}

int distance(int x1, int y1, int x2, int y2)
{
    int num_diag = min(abs(x1 - x2), abs(y1 - y2));
    return num_diag + abs(abs(x1 - x2) - abs(y1 - y2));
}