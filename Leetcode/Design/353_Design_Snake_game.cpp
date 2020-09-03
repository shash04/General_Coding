// Design a Snake game that is played on a device with screen size = width x height. Play the game online if you are not familiar with the game.
// The snake is initially positioned at the top left corner (0,0) with length = 1 unit.
// You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.
// Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.
// When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

// Example:

// Given width = 3, height = 2, and food = [[1,2],[0,1]].

// Snake snake = new Snake(width, height, food);

// Initially the snake appears at position (0,0) and the food at (1,2).

// |S| | |
// | | |F|

// snake.move("R"); -> Returns 0

// | |S| |
// | | |F|

// snake.move("D"); -> Returns 0

// | | | |
// | |S|F|

// snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )

// | |F| |
// | |S|S|

// snake.move("U"); -> Returns 1

// | |F|S|
// | | |S|

// snake.move("L"); -> Returns 2 (Snake eats the second food)

// | |S|S|
// | | |S|

// snake.move("U"); -> Returns -1 (Game over because snake collides with border)

// https://leetcode.com/problems/design-snake-game/

// *********************************************************************************************************************************
// Using Deque
// *********************************************************************************************************************************
/*
track co-ordinates covered by snake (DEQUE data structure)

death conditions -
- next co-ordinates are already covered by snake
- goes out of screen (boundary conditions)
- return -1

For every valid move -
- remove last co-ordinates covered by snake (pop_front)
- add next co-ordinates to deque
- return score

If food co-ordinates == next co-ordinates
- no removal, just add these co-ord to deque
- score++
- update food co-ord with next food co-ord (copy of food locations)
- return score

*/

class SnakeGame {
    int nR;
    int nC;
    queue<pair<int, int>> foodQ;
    deque<pair<int, int>> dq;
    set<pair<int, int>> snakeLoc;
    
    int score;
    
    pair<int, int> foodLoc;
    
    unordered_map<string, pair<int, int>> dirs = {{"U", {-1, 0}}, {"D", {1, 0}}, {"L", {0, -1}}, {"R", {0, 1}}};
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        nR = height;
        nC = width;
        
        score = 0;
        
        for(vector v : food)
            foodQ.push(make_pair(v[0], v[1]));
        
        foodLoc = foodQ.front();
        foodQ.pop();
        
        dq.push_back(make_pair(0, 0));
        snakeLoc.insert(make_pair(0, 0));
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int R = dq.back().first + dirs[direction].first;
        int C = dq.back().second + dirs[direction].second;
        
        // next is food location
        if(R == foodLoc.first && C == foodLoc.second)
        {
            foodLoc = foodQ.front();
            foodQ.pop();
            
            score++;
        }
        else
        {
            pair<int, int> lastLoc = dq.front();
            snakeLoc.erase(lastLoc);
            dq.pop_front();
        }
        
        // Reason to put after dq is updated is to take care of case when next loc is curr tail end
        // if snakeLoc is checked before pop_front and erase, it will result in -1 return value
        if(R < 0 || R >= nR || C < 0 || C >= nC || snakeLoc.count(make_pair(R, C)))
            return -1;
        
        dq.push_back(make_pair(R, C));
        snakeLoc.insert(make_pair(R, C));
    
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */

// *********************************************************************************************************************************
// Using queue
// *********************************************************************************************************************************
class SnakeGame {
    int score;
    
    map<string, pair<int, int>> dirs;
    
    queue<pair<int, int>> foodQ;
    pair<int, int> currFood;
    
    set<pair<int, int>> snakeLoc;
    queue<pair<int, int>> snakeQ;
    pair<int, int> currSnake;
    
    int nR;
    int nC;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        score = 0;
        nR = height;
        nC = width;
        
        for(auto& entry : food)
            foodQ.push(make_pair(entry[0], entry[1]));
        
        currFood = foodQ.front();
        foodQ.pop();
        
        currSnake = make_pair(0, 0);
        
        dirs["U"] = make_pair(-1, 0);
        dirs["L"] = make_pair(0, -1);
        dirs["R"] = make_pair(0, 1);
        dirs["D"] = make_pair(1, 0);
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        pair<int, int> dir = dirs[direction];
        
        int r = dir.first + currSnake.first;
        int c = dir.second + currSnake.second;
        
        if(r >= nR || r < 0 || c >= nC || c < 0 || snakeLoc.count({r,c}))
            return -1;
        
        snakeQ.push({r, c});
        snakeLoc.insert({r, c});
        
        if(currFood.first == r && currFood.second == c)
        {
            score++;
            currFood = foodQ.front();
            foodQ.pop();
        }
        else
        {
            pair<int, int> evict = snakeQ.front();
            snakeQ.pop();
            snakeLoc.erase(evict);
        }
        
        currSnake.first = r;
        currSnake.second = c;
        
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */