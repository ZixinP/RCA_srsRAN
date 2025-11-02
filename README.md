# RCA_srsRAN
srsRAN scheduler algorithme implementation method example

*In lib/scheduler/policy/CMakeLists.txt* :

#.../n
/n
add_library(srsran_scheduler_policy /n
  scheduler_policy_factory.cpp /n
  scheduler_time_pf.cpp /n
  scheduler_time_rr.cpp /n
  scheduler_time_greedy.cpp # <-- /n
) /n
/n
#...



*In yaml configuration file* :

cell_cfg:/n
  #other cellule config /n
  sched_expert_cfg: /n
    policy_sched_cfg: /n
      greedy_sched: {} # activate greedy /n
      # pf_sched:...  # make sure other algo have been commented
 
