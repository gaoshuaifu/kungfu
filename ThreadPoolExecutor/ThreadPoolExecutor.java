class SequentialExecutor {
  private ThreadPool myPool;
  private boolean myBusy;
  private LinkedList<Runnable> myQueue;

  SequentialExecutor(ThreadPool pool) {
    myPool = pool;
    myBusy = false;
    myQueue = new LinkedList<Runnable>();
  }
  public synchronized void post(Runnable r) {
    myQueue.add(r);
    if (!myBusy) {
      myBusy = true;
      myPool.post(new MyRunnable());
    }
  }
  private class MyRunnable implements Runnable {
    public void run() {
      while (true) {
        Runnable runnable;
        synchronized (this) {
          if (myQueue.isEmpty()) {
            myBusy = false;
            return;
          }
          runnable = myQueue.remove();
        }
        runnable.run();
      }
    }
  }
}
