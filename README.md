# RCA_srsRAN
srsRAN scheduler algorithme implementation method example

*In lib/scheduler/policy/CMakeLists.txt* :

#...

add_library(srsran_scheduler_policy  
&ensp;scheduler_policy_factory.cpp   
&ensp;scheduler_time_pf.cpp    
&ensp;scheduler_time_rr.cpp   
&ensp;scheduler_time_greedy.cpp # <--   
)   
  
#...  



*In yaml configuration file* :  
  
cell_cfg:  
  #other cellule config   
  sched_expert_cfg:   
    policy_sched_cfg:   
      greedy_sched: {} # activate greedy   
      # pf_sched:...  # make sure other algo have been commented  
 
