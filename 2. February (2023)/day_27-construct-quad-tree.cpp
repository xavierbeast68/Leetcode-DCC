//* https://leetcode.com/problems/construct-quad-tree/
//* https://www.youtube.com/watch?v=UQ-1sBMV0v4
//* https://www.youtube.com/watch?v=0ephEe1al5k


/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

    // Node* constructQuadTree(vector<vector<int>> grid, int rowStart, int rowEnd, int colStart, int colEnd){
    //     if(rowStart > rowEnd || colStart > colEnd){
    //         return NULL; // Node()
    //     }

    //     bool isLeaf = true;
    //     int val = grid[rowStart][colStart];
    //     for(int i = rowStart; i <= rowEnd; i++){
    //         for(int j = colStart; j <= colEnd; j++){
    //             if(val != grid[i][j]){
    //                 isLeaf = false;
    //                 break;
    //             }
    //         }

    //         // if isLeaf = false
    //         if(!(isLeaf)){
    //             break;
    //         }
    //     }

    //     // isLeaf = true
    //     if(isLeaf){
    //         return new Node(val, isLeaf); // new Node(bool _val, bool _isLeaf)
    //     }

    //     int rowMid = (rowStart + rowEnd) / 2;
    //     int colMid = (colStart + colEnd) / 2;

    //     Node* topLeft = constructQuadTree(grid, rowStart, rowMid, colStart, colMid);
    //     Node* topRight = constructQuadTree(grid, rowStart, rowMid, colMid + 1, colEnd);
    //     Node* bottomLeft = constructQuadTree(grid, rowMid + 1, rowEnd, colStart, colMid);
    //     Node* bottomRight = constructQuadTree(grid, rowMid + 1, rowEnd, colMid + 1, colEnd);

    //     return new Node(val, false, topLeft, topRight, bottomLeft, bottomRight); // new Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight)
    // }

    Node* constructTree(vector<vector<int>> grid, int n, int r, int c){
        if(n == 0){
            return NULL;
        }
        
        bool allsame = true;
        int val = grid[r][c];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(val != grid[r + i][c + j]){
                    allsame = false;
                    break;
                }
            }
            if(!(allsame)){
                break;
            }
        }

        // isLeaf
        if(allsame){
            return new Node(val, true);
        }

        n = n / 2;
        Node* topLeft = constructTree(grid, n, r, c);
        Node* topRight = constructTree(grid, n, r, c + n);
        Node* bottomLeft = constructTree(grid, n, r + n, c);
        Node* bottomRight = constructTree(grid, n, r + n, c + n);

        return new Node(val, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // constructQuadTree(grid, top-left, top-right, bottom-left, bottom-right);
        // return constructQuadTree(grid, 0, n-1, 0, n-1);

        // another method, only using n in recursive function
        return constructTree(grid, n, 0, 0);
    }
};