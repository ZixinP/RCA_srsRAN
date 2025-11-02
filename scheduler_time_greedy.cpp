#include "scheduler_time_greedy.h"
#include "srsran/mac/scheduler/policy/ue_allocator.h"
#include "srsran/mac/ue_sched_ctx.h"
#include "srsran/phy/common/phy_cfg_nr.h"

namespace srsran {
namespace mac {

// This struct will be defined in scheduler_policy_factory.h later
struct greedy_sched_args_t {};

scheduler_time_greedy::scheduler_time_greedy(const greedy_sched_args_t&, srslog::logger_t& parent_logger)
    : logger(parent_logger)
{
  SRSRAN_LOG_INFO(logger, "Greedy scheduler instance created.");
}

void scheduler_time_greedy::ue_added(const ue_sched_handle& ue)
{
  SRSRAN_LOG_INFO(logger, "UE with rnti=%d added to Greedy scheduler.", ue.get_rnti());
  active_ues.push_back(ue.get_rnti());
}

void scheduler_time_greedy::ue_removed(uint16_t rnti)
{
  SRSRAN_LOG_INFO(logger, "UE with rnti=%d removed from Greedy scheduler.", rnti);
  std::erase(active_ues, rnti);
}

void scheduler_time_greedy::tick_dl(slot_point slot, ue_sched_ctx_dl& ues, resource_grid& res_grid)
{
  SRSRAN_LOG_DEBUG(logger, "Greedy DL tick running for slot=%d", slot.slot);

  for (uint16_t rnti : active_ues) {
    ue_sched_handle_dl* ue = ues.get_ue(rnti);
    if (!ue |

| ue->get_buffer_status().total_bytes == 0) {
      continue; // Skip UEs with no data
    }

    // Greedy choice: serve the first UE with data
    SRSRAN_LOG_DEBUG(logger, "Greedy scheduler is serving UE with rnti=%d", rnti);

    // Attempt to allocate all available PRBs to this UE
    ue_allocator allocator(*ue, res_grid, slot);
    allocator.run_dl();

    // In a simple greedy approach, we stop after serving one UE per tick.
    return;
  }
}

void scheduler_time_greedy::tick_ul(slot_point slot, ue_sched_ctx_ul& ues, resource_grid& res_grid)
{
  // For simplicity, the UL logic can be left empty or implement a similar greedy approach
  // based on Buffer Status Reports (BSR) or Scheduling Requests (SR).
  SRSRAN_LOG_DEBUG(logger, "Greedy UL tick running for slot=%d", slot.slot);
}

} // namespace mac
} // namespace srsran
