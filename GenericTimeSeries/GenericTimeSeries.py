import collections

EmpRange = collections.namedtuple('EmpRange', ['eid', 'start_time', 'end_time'])
EmpEvent = collections.namedtuple('EmpEvent', ['eid', 'time', 'starting'])
TimeRange = collections.namedtuple('TimeRange', ['start_time', 'end_time', 'value'])

def count_emps(emps):
    return len(emps)

def list_emps(emps):
    return list(emps)

class Solution(object):
  def __init__(self, fn):
    self.fn = fn

  def _transform_to_events(self, emp_ranges):
    emp_events = list()
    for emp_range in emp_ranges:
      emp_events.append(EmpEvent(emp_range[0], emp_range[1], True))
      emp_events.append(EmpEvent(emp_range[0], emp_range[2], False))
    return sorted(emp_events, key = lambda tub: tub.time)

  def time_series(self, emp_ranges):
    emp_events = self._transform_to_events(emp_ranges)

    prev_event = emp_events[0]
    emps = set()
    emps.add(prev_event.eid)

    time_ranges = list()
    for emp_event in emp_events[1:]:
      curr_event = emp_event
      time_ranges.append(TimeRange(prev_event.time, curr_event.time, self.fn(emps)))
      if curr_event.starting:
        emps.add(curr_event.eid)
      else:
        emps.remove(curr_event.eid)
      prev_event = curr_event
    return time_ranges

def main():
  emp_ranges = [
    EmpRange(1, 1000, 2000),
    EmpRange(2, 1500, 3000),
    EmpRange(3, 1700, 2100),
  ]

  fns = [count_emps, list_emps]
  for fn in fns:
      solution = Solution(fn)
      print(solution.time_series(emp_ranges))
      print()

if __name__ == "__main__":
  main()
