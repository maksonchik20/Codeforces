from datetime import datetime, timedelta

def last_day_of_month(any_day):
    next_month = any_day.replace(day=28) + timedelta(days=4)
    return (next_month - timedelta(days=next_month.day))

type_ = input()
start, end = input().split()
start_year, start_month, start_day = map(int, start.split("-"))
end_year, end_month, end_day = map(int, end.split("-"))

# print(last_day_of_month(datetime(start_year, 2, 1)))
if type_ == "MONTH":
    date_start = datetime(start_year, start_month, start_day)
    date_end = datetime(end_year, end_month, end_day)
    while date_start < date_end:
        if last_day_of_month(date_start) > date_end:
            print(date_start.date(), date_end.date())
        else:
            print(date_start.date(), last_day_of_month(date_start).date())
        date_start = last_day_of_month(date_start) + timedelta(days=1)
# elif type_ == 'WEEK':


    