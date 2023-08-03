//
// This test verifies that a socket correctly indicates not ready to write when
// poll()ed if a subsequent write() would block
//
//

#include <assert.h>
#include <poll.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

static void timeout(int signum)
{
  exit(1);
}

int main()
{
  char wbuf[100] = { 0, };
  int out;

  signal(SIGALRM, timeout);

  {
    int sv[2];
    int s;

    s = socketpair (AF_UNIX, SOCK_STREAM, 0, sv);
    assert (s == 0);

    out = sv[0];
  }

  size_t in_flight = 0;
  while (1)
    {
      struct pollfd fds[1];
      fds[0].fd = out;
      fds[0].events = POLLOUT;

      int r = poll(fds, 1, 0);
      assert(r >= 0);

      // fd is not ready to write
      if (!(fds[0].revents & POLLOUT))
        break;

      alarm(5);

      // otherwise, fd is ready to write, implies some data may be written without blocking
      ssize_t s = write (out, wbuf, sizeof wbuf);
      assert (s > 0);
      in_flight += s;
      printf("%zd written, total in_flight %zd\n", s, in_flight);

      alarm(0);
    }
}
