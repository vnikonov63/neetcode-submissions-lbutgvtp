class DynamicArray {
private:
    int* data;
    int size;
    int capacity;

public:
    DynamicArray(int capacity) {
        this->capacity = capacity;
        data = new int[capacity];
        size = 0;
    }

    int get(int i) {
        return data[i];
    }

    void set(int i, int n) {
        data[i] = n;
    }

    void pushback(int n) {
        if (size == capacity)
            resize();

        data[size] = n;
        ++size;

    }

    int popback() {
        size--;
        return data[size];
    }

    void resize() {
        int *new_data = new int[capacity * 2];

        for (int i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity *= 2;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
