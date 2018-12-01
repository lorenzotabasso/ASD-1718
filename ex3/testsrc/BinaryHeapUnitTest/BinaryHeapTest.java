package BinaryHeapUnitTest;

import static org.junit.Assert.*;
import org.junit.Test;
public class BinaryHeapTest {
/*
    @org.junit.Test
    public void getHeap() {
        Integer[] array = { 3,5,6,7,23,45,1};
        BinaryHeap<Integer> heap = new BinaryHeap<>(array);
        assertArrayEquals(array,heap.getHeap());
    }
*/

    @org.junit.Test
    public void add() {
        Integer[] array = { 3,5,6,7,23,45,1};
        BinaryHeap<Integer> heap = new BinaryHeap<>(array);
        heap.add(0);
        assertEquals(8, heap.length());
        assertEquals("correct element at head of heap", new Integer(0), heap.peek());
    }

    @org.junit.Test
    public void remove() {
        Integer[] array = { 3,5,6,7,23,45,1};
        BinaryHeap<Integer> heap = new BinaryHeap<>(array);
        heap.remove(1);
        heap.remove(5);
        assertEquals(5, heap.length());

    }
/*
    @org.junit.Test
    public void remove1() {
    }
*/
    @org.junit.Test
    public void poll() {
        Integer[] array = { 3,5,6,7,23,45,1};
        BinaryHeap<Integer> heap = new BinaryHeap<>(array);
    heap.poll();
        int x = heap.peek();
    assertEquals(3, x);
    }

    @org.junit.Test
    public void isEmpty() {
        Integer[] array = {};
        BinaryHeap<Integer> heap = new BinaryHeap<>(array);
        assertEquals(0,heap.length());
    }

    @org.junit.Test
    public void peek() {
        Integer[] array = {2,5,4,6,9};
        BinaryHeap<Integer> heap = new BinaryHeap<>(array);
        assertEquals(new Integer(2), heap.peek());
    }

    @org.junit.Test
    public void length() {
        Integer[] array = {2,5,4,6,9};
        BinaryHeap<Integer> heap = new BinaryHeap<>(array);
        assertEquals(5, heap.length());
        heap.add(14);
        assertEquals(6, heap.length());
    }

}