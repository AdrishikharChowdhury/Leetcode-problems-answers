import java.util.*;

class AllOne {
    private Map<String, Node> map;
    private Node head, tail;

    private class Node {
        int count;
        Set<String> keys;
        Node prev, next;

        Node(int count) {
            this.count = count;
            this.keys = new HashSet<>();
        }
    }

    public AllOne() {
        map = new HashMap<>();
        head = new Node(0);
        tail = new Node(Integer.MAX_VALUE);
        head.next = tail;
        tail.prev = head;
    }
    
    public void inc(String key) {
        if (map.containsKey(key)) {
            Node node = map.get(key);
            Node next = node.next;
            if (next.count > node.count + 1) {
                Node newNode = new Node(node.count + 1);
                insertNode(newNode, node);
            }
            next = node.next;
            next.keys.add(key);
            node.keys.remove(key);
            map.put(key, next);
            if (node.keys.isEmpty()) {
                removeNode(node);
            }
        } else {
            if (head.next.count > 1) {
                Node newNode = new Node(1);
                insertNode(newNode, head);
            }
            head.next.keys.add(key);
            map.put(key, head.next);
        }
    }
    
    public void dec(String key) {
        Node node = map.get(key);
        if (node.count > 1) {
            Node prev = node.prev;
            if (prev.count < node.count - 1) {
                Node newNode = new Node(node.count - 1);
                insertNode(newNode, prev);
            }
            prev = node.prev;
            prev.keys.add(key);
            map.put(key, prev);
        } else {
            map.remove(key);
        }
        node.keys.remove(key);
        if (node.keys.isEmpty()) {
            removeNode(node);
        }
    }
    
    public String getMaxKey() {
        return tail.prev.count == 0 ? "" : tail.prev.keys.iterator().next();
    }
    
    public String getMinKey() {
        return head.next.count == Integer.MAX_VALUE ? "" : head.next.keys.iterator().next();
    }

    private void insertNode(Node node, Node prev) {
        node.prev = prev;
        node.next = prev.next;
        prev.next.prev = node;
        prev.next = node;
    }

    private void removeNode(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */