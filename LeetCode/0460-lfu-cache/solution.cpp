class LFUCache{
    int cap;
    int minFreq;
public:
    //key-->{val,freq}
    unordered_map<int,pair<int,int>> mp;

    //freq-->keys
    unordered_map<int,list<int>> freqList;

    //key->iterator in list
    unordered_map<int, list<int>::iterator> pos;

    LFUCache(int capacity){
        cap=capacity;
        minFreq=0;
    }

    void updateFreq(int key){

        int freq=mp[key].second;
        freqList[freq].erase(pos[key]);

        if(freqList[freq].empty()){
            freqList.erase(freq);

            if(minFreq==freq){
                minFreq++;
            }
        }

        mp[key].second++;
        freq++;

        freqList[freq].push_front(key);
        pos[key]=freqList[freq].begin();
    }

    int get(int key){

        if(mp.find(key)==mp.end()){
            return -1;
        }

        updateFreq(key);
        return mp[key].first;
    }

    void put(int key, int value){

        if(cap==0){
            return;
        }

        if(mp.find(key)!=mp.end()){
            mp[key].first=value;
            updateFreq(key);
            return;
        }

        if(mp.size()==cap){
            //lru in minFreq
            int delKey=freqList[minFreq].back();
            freqList[minFreq].pop_back();

            if(freqList[minFreq].empty()){
                freqList.erase(minFreq);
            }

            mp.erase(delKey);
            pos.erase(delKey);
        }

        mp[key]={value,1};
        freqList[1].push_front(key);
        pos[key]=freqList[1].begin();
        minFreq=1;
    }
};
