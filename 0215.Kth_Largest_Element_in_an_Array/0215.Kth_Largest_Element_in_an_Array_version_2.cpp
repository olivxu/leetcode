// 方法二：手动实现一个大小为k的小根堆

class Solution {
public:
    void shiftUp(vector<int> &heap, int index) {
        if (index == 0)
            return;
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(heap[parent], heap[index]);
            shiftUp(heap, parent);
        }
        return;
    }

    void shiftDown(vector<int> &heap, int index, int heap_size) {
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;

        // left_child 和 right_child 都超出范围， return
        if (left_child >= heap_size)
            return;

        // left_child 没有超出范围，right_child超出范围
        if (left_child < heap_size && right_child >= heap_size) {
            if (heap[index] > heap[left_child]) {
                swap(heap[index], heap[left_child]);
                shiftDown(heap, left_child, heap_size);
            }
        }

        // left_child 和 right_child 都没有超出范围, 左子小于右子
        if (right_child < heap_size && heap[left_child] < heap[right_child]) {
            if (heap[index] > heap[left_child]) {
                swap(heap[index], heap[left_child]);
                shiftDown(heap, left_child, heap_size);
            }
        }

        // left_child 和 right_child 都没有超出范围, 左子大于等于右子
        if (right_child < heap_size && heap[left_child] >= heap[right_child]) {
            if (heap[index] > heap[right_child]) {
                swap(heap[index], heap[right_child]);
                shiftDown(heap, right_child, heap_size);
            }
        }

        return;
    }

    // 维护一个大小为k的小根堆，里面存最大的k个数
    void insertHeap(vector<int> &heap, int num, int cnt, int k) {
        if (cnt == 0)
            heap[0] = num;
        else {
            if (cnt < k) {
                heap[cnt] = num;
                shiftUp(heap, cnt);
            }
            else {
                // 更换根
                if (heap[0] < num) {
                    heap[0] = num;
                    shiftDown(heap, 0, k);
                }
            }
        }
        return;
    }

    int findKthLargest(vector<int> &nums, int k) {
        vector<int> heap(k);
        int len = nums.size();

        int cnt = 0;
        for (int i = 0; i < len; i++) {
            insertHeap(heap, nums[i], cnt, k);
            cnt++;
        }

        return heap[0];
    }
};
