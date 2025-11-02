# RCA_srsRAN
srsRAN scheduler algorithme implementation method example

In lib/scheduler/policy/CMakeLists.txt :

#...

add_library(srsran_scheduler_policy
  scheduler_policy_factory.cpp
  scheduler_time_pf.cpp
  scheduler_time_rr.cpp
  scheduler_time_greedy.cpp # <--
)

#...
