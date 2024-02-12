class HitCounter {

    Map<Integer, Integer> hitMap;

    public HitCounter() {
        hitMap = new HashMap<>();
    }

    public void hit(int timestamp) {
        hitMap.put(timestamp, hitMap.getOrDefault(timestamp, 0) + 1);
    }

    public int getHits(int timestamp) {
        int hits = 0;
        int start = Math.max(timestamp - 299, 1);

        for (int i = start; i <= timestamp; i++) {
            if (hitMap.containsKey(i)) {
                hits += hitMap.get(i);
            }
        }

        return hits;
    }
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */