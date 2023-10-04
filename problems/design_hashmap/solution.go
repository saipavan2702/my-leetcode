type MyHashMap struct {
    hash map[int]int
}


func Constructor() MyHashMap {
    return MyHashMap{hash:make(map[int]int)}
}


func (this *MyHashMap) Put(key int, val int)  {
    this.hash[key]=val
}


func (this *MyHashMap) Get(key int) int {
    if val,have:=this.hash[key];  have {
        return val
    }
    return -1
}


func (this *MyHashMap) Remove(key int)  {
    delete(this.hash,key)
}


/**
 * Your MyHashMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(key,value);
 * param_2 := obj.Get(key);
 * obj.Remove(key);
 */