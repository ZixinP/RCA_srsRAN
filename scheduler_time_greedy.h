#ifndef SRSRAN_SCHEDULER_TIME_GREEDY_H
#define SRSRAN_SCHEDULER_TIME_GREEDY_H

#include "srsran/mac/scheduler/policy/scheduler_policy.h"
#include "srsran/srslog/srslog.h"

namespace srsran {
namespace mac {

// Forward declaration for configuration arguments struct
struct greedy_sched_args_t;

class scheduler_time_greedy : public scheduler_policy {
public:
  // Constructor that takes configuration arguments
  explicit scheduler_time_greedy(const greedy_sched_args_t& args, srslog::logger_t& logger);

  // Override the interface from scheduler_policy
  void tick_dl(slot_point slot, ue_sched_ctx_dl& ues, resource_grid& res_grid) override;
  void tick_ul(slot_point slot, ue_sched_ctx_ul& ues, resource_grid& res_grid) override;
  void ue_added(const ue_sched_handle& ue) override;
  void ue_removed(uint16_t rnti) override;
  std::string name() const override { return "greedy_scheduler"; }

private:
  srslog::logger_t& logger;
  // A simple list to keep track of active UEs by their RNTI
  std::vector<uint16_t> active_ues;
};

} // namespace mac
} // namespace srsran

#endif // SRSRAN_SCHEDULER_TIME_GREEDY_H
