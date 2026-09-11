class LFUCache {
public:
    int capacity;
    int minFreq;

    unordered_map<int, int> keyValue;
    unordered_map<int, int> keyFreq;

    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> keyPosition;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyValue.find(key) == keyValue.end()) {
            return -1;
        }

        int freq = keyFreq[key];

        freqList[freq].erase(keyPosition[key]);

        if (freqList[freq].empty()) {
            freqList.erase(freq);

            if (minFreq == freq) {
                minFreq++;
            }
        }

        keyFreq[key]++;

        freqList[freq + 1].push_back(key);
        keyPosition[key] = prev(freqList[freq + 1].end());

        return keyValue[key];
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }

        if (keyValue.find(key) != keyValue.end()) {
            keyValue[key] = value;
            get(key);
            return;
        }

        if (keyValue.size() == capacity) {
            int deleteKey = freqList[minFreq].front();

            freqList[minFreq].pop_front();

            keyValue.erase(deleteKey);
            keyFreq.erase(deleteKey);
            keyPosition.erase(deleteKey);
        }

        keyValue[key] = value;
        keyFreq[key] = 1;

        freqList[1].push_back(key);
        keyPosition[key] = prev(freqList[1].end());

        minFreq = 1;
    }
};