class SnapshotArray {
private:
    // index -> [snap_id -> {till which snap_id value is same, value}]
    map<int,map<int,pair<int,int>>> mp;
    int id = 0;    
public:    
    SnapshotArray(int n){}

    void set(int index, int val) {
        auto &map = mp[index];
        if(map.size()){
            auto &pp = (*--map.upper_bound(id)).second;
            pp.first = id-1;
        }
        map[id] = {id,val};
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
       auto &map = mp[index];
       if(map.empty()) return 0;
       auto ub = map.upper_bound(snap_id);
       if(ub == map.begin()) return 0;
       auto &pp = (*--ub).second;
       if(pp.first >= snap_id or ++ub == map.end()) return pp.second;
       return 0;
    }
};
/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */