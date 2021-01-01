/* ------------------------------------------------------------------|
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

 

示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：true
示例 2：


输入：root = [1,2,2,3,3,null,null,4,4]
输出：false
示例 3：

输入：root = []
输出：true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/balanced-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	自底向上法
*
*	执行用时：20 ms, 在所有 C++ 提交中击败了72.19%的用户
*	内存消耗：21.6 MB, 在所有 C++ 提交中击败了30.08%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

int check(TreeNode* root) {
    if (!root) {
        return 0;
    }
    //获得左子树和右子树的最大深度
    int heightl = check(root->left);
    int heightr = check(root->right);
    //如果左子树或右子树的最大深度为-1，或者相差大于1，就说明不符合要求，返回-1直接退出，-1即为错误标识
    if (heightl == -1 || heightr == -1 || abs(heightl - heightr) > 1) {
        return -1;
    }
    //不然则返回最大子树深度+1
    return max(heightl, heightr) + 1;
}

bool isBalanced(TreeNode* root) {
    return check(root) != -1;
}