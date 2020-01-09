//
// Created by hector on 2020/1/7.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <climits>
#include <unordered_map>
#include <vector>
#include <ctime>

using namespace std;

class Node {
        public:
        Node() {
            val = INT_MIN;
            left = NULL;
            right = NULL;
        }

        Node(int v, Node *l, Node *r) {
            val = v;
            left = l;
            right = r;
        }

        int val;
        Node *left;
        Node *right;
        Node *parent;
};

class Heap {
        public:
        Heap() {
            Node *stub = new Node(INT_MIN, NULL, NULL);
            stub->parent = NULL;
            not_full_node.push_back(stub);
            head = stub;
            size = 0;
            cout << "after creating the heap, not_full_node = " << endl;
            print_not_full_node();
        }

        void heap_insert(int val) {
            //first insert this new node as the child of the last node
            Node *to_insert = new Node(val, NULL, NULL);
            last_node = to_insert;
            not_full_node.push_back(to_insert);
            Node *insert_point = not_full_node.front();
            if (insert_point->left == NULL) {
                insert_point->left = to_insert;
                to_insert->parent = insert_point;
            } else {
                insert_point->right = to_insert;
                to_insert->parent = insert_point;
                not_full_node.pop_front();
            }
            //this should be safe as the last node should not have any children
            //then heapfy the heap in a bottom-up manner.
            heapfy_bottom_up();
            //this function won't change the head_ptr
            ++size;
        }

        int get_max() {
            //return the max value of the heap
            int ret = head->val;
            Node *last_node = not_full_node.back();
            not_full_node.pop_back();
            head->val = last_node->val;
            Node *last_node_parent = last_node->parent;
            if (last_node_parent->left == last_node) last_node_parent->left = NULL;
            else {
                last_node_parent->right = NULL;
                not_full_node.push_front(last_node_parent);
            }
            delete last_node;
            heapfy_top_down();
            --size;
            return ret;
        }

        void heapfy_bottom_up() {
            Node *curr = last_node;
            while (curr->parent != NULL && curr->val > curr->parent->val) {
                //we only need to swap the val of the two nodes
                swap(curr->val, curr->parent->val);
                curr = curr->parent;
            }
        }

        void heapfy_top_down() {
            //TODO: how to make the heap relatively balanced.
            Node *curr = head;
            while (curr->left != NULL || curr->right != NULL) {
                if (curr->left != NULL && curr->right != NULL) {
                    int larger = max(curr->left->val, curr->right->val);
                    if (curr->val < larger) {
                        if (larger == curr->left->val) swap(curr->val, curr->left->val);
                        else swap(curr->val, curr->right->val);
                    } else {
                        break;
                    }
                } else if (curr->left != NULL) {
                    if (curr->val < curr->left->val) {
                        swap(curr->val, curr->left->val);
                    } else {
                        //reach a proper position, break
                        break;
                    }
                } else {
                    //we consider the right branch only if the left one is empty
                    if (curr->val < curr->right->val) {
                        swap(curr->val, curr->right->val);
                    } else {
                        break;
                    }
                }

            }
        }

        void print_heap() {
            //print the heap in bfs manner
            queue<Node *> bfs_queue;
            bfs_queue.push(head);
            while (!bfs_queue.empty()) {
                Node *front = bfs_queue.front();
                cout << front->val << endl;
                if (front->left != NULL) bfs_queue.push(front->left);
                if (front->right != NULL) bfs_queue.push(front->right);
                bfs_queue.pop();
            }
            cout << "heap print finished..." << endl;
        }

        bool is_empty() {
            return size == 0;
        }

        int get_size() {
            return size;
        }

        void print_not_full_node() {
            for (auto val : not_full_node) cout << val << " ";
            cout << "not_full" << endl;
        }

        private:
        Node *head;
        deque<Node *> not_full_node;
        Node *last_node;
        int32_t size;
};

class Solution {
        public:
        int lastStoneWeight(vector<int> &stones) {
            Heap max_heap = Heap();
            for (auto val : stones) {
                max_heap.heap_insert(val);
            }
            //max_heap.print_heap();
            while (max_heap.get_size() >= 2) {
                max_heap.print_heap();

                int weight_a = max_heap.get_max();
                int weight_b = max_heap.get_max();
                int remain = abs(weight_a - weight_b);
                cout << "smash " << weight_a << " and " << weight_b << " remains " << remain << endl;
                cout << "remains " << max_heap.get_size() << " nodes in the heap" << endl;
                if (remain != 0) max_heap.heap_insert(remain);

            }
            return max_heap.is_empty() ? 0 : max_heap.get_max();
        }
};


int main() {
    vector<int> stone = {1, 3};
    Solution s;
    cout << s.lastStoneWeight(stone);

}

//int test() {
//    Heap h = Heap();
//    std::vector<int> vec(10000);
//    for (int i = 0; i < 10000; ++i) {
//        int rand_num = rand()%1000;
//        vec[i] = rand_num;
//        h.heap_insert(rand_num);
//    }
//
//    clock_t t1 = clock();
//    for(int j = 0; j < 10000; ++j) {
//        auto it = std::max_element(vec.begin()+j, vec.end());
//    }
//    std::cout << (clock() - t1) * 1.0 / CLOCKS_PER_SEC * 1000 << std::endl;
//
//    t1 = clock();
//    for(int j = 0; j < 10000; ++j) {
//        int tmp = h.get_max();
//    }
//    std::cout << (clock() - t1) * 1.0 / CLOCKS_PER_SEC * 1000 << std::endl;
//
//
//    h.print_heap();
//}