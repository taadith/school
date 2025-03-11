#include <vector>
#include <iostream>

using namespace std;

class st {
private:
    vector<long long> tree;
    int n;

    // build the segment tree
    void build(vector<long long>& nums, int node, int start, int end) {
        if (start == end)
            tree[node] = nums[start];
        else {
            int mid = (start + end) / 2;
            build(nums, 2 * node + 1, start, mid); // Build left subtree
            build(nums, 2 * node + 2, mid + 1, end); // Build right subtree
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // Update current node
        }
    }

    // update a value at a specific index
    void update(int node, int start, int end, int index, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            // update left subtree
            if (index <= mid)
                update(2 * node + 1, start, mid, index, val);
            // update right subtree
            else
                update(2 * node + 2, mid + 1, end, index, val);
            
            // update current node
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    // query the sum of elements in a range
    int query(int node, int start, int end, int left, int right) {
        if (start > right || end < left) {
            return 0; // Completely outside the range
        } else if (start >= left && end <= right) {
            return tree[node]; // Completely inside the range
        } else {
            int mid = (start + end) / 2;
            int sumLeft = query(2 * node + 1, start, mid, left, right); // Query left subtree
            int sumRight = query(2 * node + 2, mid + 1, end, left, right); // Query right subtree
            return sumLeft + sumRight; // Merge results from left and right subtrees
        }
    }

public:
    // Constructor
    st(vector<long long>& nums) {
        n = nums.size();
        if (n > 0) {
            tree.resize(4 * n); // Allocate space for the tree
            build(nums, 0, 0, n - 1); // Build the segment tree
        }
    }

    // Update the value at index 'index' to 'val'
    void update(int index, int val) {
        if (index >= 0 && index < n) {
            update(0, 0, n - 1, index, val);
        }
    }

    // Query the sum of elements in the range [left, right]
    int query(int left, int right) {
        if (left <= right && left >= 0 && right < n) {
            return query(0, 0, n - 1, left, right);
        } else {
            return 0; // Invalid range
        }
    }
};

int main() {
    vector<long long> nums = {1, 3, 5, 7, 9, 11};
    st segment_tree(nums);

    // Test segment tree operations
    cout << segment_tree.query(1, 4) << endl; // Query sum of elements in the range [1, 4]
    segment_tree.update(2, 10); // Update element at index 2 to 10
    cout << segment_tree.query(1, 4) << endl; // Query sum of elements in the range [1, 4]

    return 0;
}