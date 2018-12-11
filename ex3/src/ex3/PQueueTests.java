package ex3;

import org.junit.Test;
import static org.junit.Assert.*;
/**
 * @author Lorenzo Tabasso, mat: 812499
 * @author Andrea Malgaoli, mat: 823429
 */
public class PQueueTests{
    @Test
    public void testEmptyQueue(){
        PQueue queue = new PQueue<>();
        assertTrue(queue.isEmpty());
    }

    //We check also the "false" of .isEmpty()
    @Test
    public void testInsertInQueue(){
        PQueue<Integer, Long> queue = new PQueue<>();
        assertTrue(queue.insert(28, 1L));
        assertFalse(queue.isEmpty());
    }

    @Test
    public void testPullFirstOnEmptyQueue(){
        PQueue queue = new PQueue<>();
        assertNull(queue.pullFirst());
    }

    @Test
    public void testPullFirst(){
        PQueue<Integer, Long> queue = new PQueue<>();
        queue.insert(1, 3L);
        queue.insert(2, 6L);
        queue.insert(3, 2L);
        queue.insert(4, 7L);
        queue.insert(28, 1L);

        Integer pulledItem = queue.pullFirst();
        assertNotNull(pulledItem);
        assertEquals(pulledItem,(Integer) 28);
    }

    @Test
    public void testEmptyQueueAfterPull(){
        PQueue<Integer, Long> queue = new PQueue<>();
        queue.insert(1, 1L);
        queue.pullFirst();
        assertTrue(queue.isEmpty());
    }

    @Test
    public void testPeekOnEmptyQueue(){
        PQueue<Integer, Long> queue = new PQueue<>();

        Integer pulledItem = queue.peek();
        assertNull(pulledItem);
    }

    @Test
    public void testPeek(){
        PQueue<Integer, Long> queue = new PQueue<>();
        queue.insert(28, 1L);

        Integer pulledItem = queue.peek();
        assertNotNull(pulledItem);
        assertEquals(pulledItem,(Integer) 28);
    }
}
