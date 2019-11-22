#include <bits/stdc++.h>

int main () {
  std::string msg, str;
  std::cin >> msg >> str;

  long long ans = 0;
  //printf ("msg: %d, std: %d, msg-str: %d\n", (int)msg.size (), (int)str.size (), (int)msg.size () - (int)str.size ());
  if (msg.size () == str.size ()) {
    int flag = 0;
    for (int j = 0; j < str.size (); j++)
      if (str[j] == msg[j])
        flag = 1;
    if (!flag)
      ans++;
    printf ("%lld\n", ans);
    return 0;
  }

  for (int i = 0; i <= msg.size () - str.size (); i++) {
    int flag = 0;
    for (int j = i; j < i + str.size (); j++) {
      //printf ("msg[%d]: %c\n", j, msg[j]);
      if (str[j-i] == msg[j])
        flag = 1;
    }
    if (!flag)
      ans++;
  }

  printf ("%lld\n", ans);
  return 0;
}
