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
&ensp;#other cellule config   
&ensp;sched_expert_cfg:   
&ensp;&ensp;policy_sched_cfg:   
&ensp;&ensp;&ensp;greedy_sched: {} # activate greedy   
&ensp;&ensp;&ensp;# pf_sched:...  # make sure other algo have been commented  
 
