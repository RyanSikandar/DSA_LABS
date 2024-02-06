#include <iostream>
#include <vector>
using namespace std;

class BinaryHeap
{
private:
    vector<int> heap;

    // Helper function to move the pushed and the elements up the heap
    void HeapifyUp(int index)
    {
        while (index > 0)
        {
            // Calculate the parent index
            int parent = (index - 1) / 2;

            // Check if the parent is greater, swap if necessary
            if (heap[parent] > heap[index])
            {
                swap(heap[index], heap[parent]);
                index = parent; // Move up to the parent index
            }
            else
                break;
        }
    }

    // Helper function to move the element down the heap
    void HeapifyDown(int index)
    {
        int number = index;
        int LeftNode = 2 * index + 1;
        int RightNode = 2 * index + 2;

        // Check if the left child exists and is smaller than the current element
        if (LeftNode < heap.size() && heap[number] > heap[LeftNode])
        {
            number = LeftNode;
        }

        // Check if the right child exists and is smaller than the current element
        if (RightNode < heap.size() && heap[number] > heap[RightNode])
        {
            number = RightNode;
        }

        // If the index has changed, swap and continue heapifying down
        if (number != index)
        {
            swap(heap[number], heap[index]);
            HeapifyDown(number);
        }
    }

public:
    // Function to get the minimum element without removing it
    int top()
    {
        if (!isEmpty())
        {
            return heap[0];
        }
        else
            cout << "Heap is empty, cannot perform function";

        return 0;
    }

    // Function to check if the heap is empty
    bool isEmpty()
    {
        return heap.empty();
    }

    // Function to remove and return the minimum element
    int pop()
    {
        if (!isEmpty())
        {
            int root = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            HeapifyDown(0);
            return root;
        }
        else
        {
            cout << "Heap is empty, cannot perform function";

            return 0;
        }
    }

    // Function to get the number of elements in the heap
    int size()
    {
        if (!isEmpty())
        {
            return heap.size();
        }
        else
            cout << "Heap is empty";
        return 0;
    }

    // Function to get the height of the heap
    int height()
    {
        if (!isEmpty())
        {
            int levels;
            // Loop to find the highest level for which the total nodes are less than the size
            for (levels = 0; (1 << levels) - 1 < heap.size(); levels++)
                ;
            return levels;
        }
        else
            cout << "The heap is empty";
    }

    // Function to print the heap
    void print()
    {
        for (auto i : heap)
        {
            cout << i << ' ';
        }
    }

    // Function to build a heap from an array
    void BuildHeap(vector<int> arrary)
    {
        heap.clear();
        for (auto i : arrary)
        {
            push(i);
        }
    }

    // Function to insert an element into the heap
    void push(int i)
    {
        heap.push_back(i);
        HeapifyUp(heap.size() - 1);
    }
};

int main()
{
    BinaryHeap minHeap;

    // Example usage:
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(7);
    minHeap.push(1);
    cout << endl;
    cout << "Min Element: " << minHeap.top() << std::endl;
    minHeap.print();

    minHeap.pop();
    cout << endl;

    cout << "After Pop:" << std::endl;
    minHeap.print();
    cout << endl;

    cout << "Heap Size: " << minHeap.size() << std::endl;
    cout << endl;

    cout << "Heap Height: " << minHeap.height() << std::endl;
    cout << endl;

    vector<int> array = {9, 5, 3, 8, 1};
    minHeap.BuildHeap(array);
    cout << "After Building Heap from Array:" << std::endl;
    minHeap.print();

    return 0;
}