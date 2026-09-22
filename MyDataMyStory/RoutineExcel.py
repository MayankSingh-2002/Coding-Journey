import openpyxl
from datetime import date, timedelta

FEELING_VALUES = [
    "Excellent",
    "Good",
    "Neutral",
    "Low",
    "Stressed"
]

SATISFACTION_VALUES = [
    "Very Satisfied",
    "Satisfied",
    "Neutral",
    "Unsatisfied",
    "Very Unsatisfied"
]

ENERGY_VALUES = [
    "High",
    "Medium",
    "Low"
]

FEELING_SCORES = {
    "Excellent": 5,
    "Good": 4,
    "Neutral": 3,
    "Low": 2,
    "Stressed": 1
}

SATISFACTION_SCORES = {
    "Very Satisfied": 5,
    "Satisfied": 4,
    "Neutral": 3,
    "Unsatisfied": 2,
    "Very Unsatisfied": 1
}

ENERGY_SCORES = {
    "High": 3,
    "Medium": 2,
    "Low": 1
}

def read_data(filename):
    workbook = openpyxl.load_workbook(filename, data_only=True)

    sheet = workbook["Daily Log"]

    data = []

    for row in sheet.iter_rows(min_row=6, values_only=True):
        if row[0] is not None:
            data.append(row)

    workbook.close()

    return data

def validate_data(data):
    validate_data = []
    invalid_records = 0
    seen_dates = []

    for row in data:
        try:
            #Checking whether each record has all required columns
            if len(row) < 14:
                invalid_records += 1
                continue

            #Checking if date format is correct in date column
            if row[0] is None:
                invalid_records += 1
                continue

            if row[0] in seen_dates:
                invalid_records +=1
                continue

            seen_dates.append(row[0])

            valid = True

            #Checking for numberical values
            for i in range(1,10):
                if row[i] is None:
                    valid = False
                    break

            if not isinstance(row[i], (int, float)):
                valid = False
                break

            if row[i] < 0:
                valid = False
                break

            #Checking other column with qualitative values
            if row[10] not in FEELING_VALUES:
                valid = False

            if row[11] not in SATISFACTION_VALUES:
                valid = False

            if row[12] not in ENERGY_VALUES:
                valid = False

            if valid:
                validate_data.append(row)
            else:
                invalid_records += 1

        except (TypeError, ValueError, IndexError):
            invalid_records += 1

    return validate_data, invalid_records

def check_continue_date(data):

    start_date = date(2026, 8, 13)
    end_date = date(2026, 9, 21)

    expected_days = 0
    missing_days = []

    recorded_dates = []

    for row in data:
        recorded_date = row[0]

        if hasattr(recorded_date, "date"):
            recorded_date = recorded_date.date()

        recorded_dates.append(recorded_date)

    current_date = start_date

    while current_date <= end_date:
        expected_days += 1

        if current_date not in recorded_dates:
            missing_days.append(current_date)

        current_date = current_date + timedelta(days=1)

    return expected_days, missing_days

def calculate_average(data, column):

    total = 0

    for row in data:
        total = total + row[column]

    average = total/len(data)

    return average

def calculate_activity_averages(data):

    averages = {}

    averages["sleep"] = calculate_average(data, 1)
    averages["fitness"] = calculate_average(data, 2)
    averages["study"] = calculate_average(data, 3)
    averages["coding"] = calculate_average(data, 4)
    averages["class"] = calculate_average(data, 5)
    averages["other"] = calculate_average(data, 7)
    averages["total_tracked"] = calculate_average(data, 8)
    averages["free_time"] = calculate_average(data, 9)

    return averages

def caluclate_experience_index(data):

    total_experience = 0

    for row in data:
        feeling_score = FEELING_SCORES[row[10]]
        satisfaction_score = SATISFACTION_SCORES[row[11]]
        energy_score = ENERGY_SCORES[row[12]]

        daily_experience = (
            feeling_score + satisfaction_score + energy_score
        )/3

        total_experience = total_experience + daily_experience

    experience_index = total_experience/len(data)

    return experience_index

def calculate_activity_indices(data):

    indices = {}

    indices["TPI"] = calculate_average(data, 4)

    study_average = calculate_average(data, 3)
    class_average = calculate_average(data, 5)
    indices["AAI"] = study_average + class_average

    indices["PhAI"] = calculate_average(data, 2)

    indices["SRI"] = calculate_average(data, 1)

    indices["ABI"] = calculate_average(data, 9)

    indices["TUI"] = calculate_average(data, 8)

    return indices

def calculate_dci(valid_days, expected_days):

    DCI = (valid_days/expected_days)*100

    return DCI

def calculate_pai(indices, experinece_index, DCI):

    PAI = (0.15*indices["TPI"] + 0.20*indices["AAI"] + 0.15*indices["PhAI"] + 0.20*indices["SRI"] + 0.15*indices["TUI"] + 0.10* experinece_index + DCI)

    return PAI

def calculate_list_average(values):
    total = 0

    for value in values:
        total = total + value

    return total/len(values)

def sleep_energy_analysis(data):

    high_sleep = []
    medium_sleep = []
    low_sleep = []

    for row in data:

        if row[12] == "High":
            high_sleep.append(row[1])

        elif row[12] == "Medium":
            medium_sleep.append(row[1])

        elif row[12] == "Low":
            low_sleep.append(row[1])

    result = {}

    if len(high_sleep) > 0:
        result["High"] = calculate_list_average(high_sleep)

    if len(medium_sleep) > 0:
        result["Medium"] = calculate_list_average(medium_sleep)

    if len(low_sleep) > 0:
        result["Low"] = calculate_list_average(low_sleep)

    return result

def study_satisafaction_analysis(data):

    very_satisfied = []
    satisfied = []
    neutral = []
    unsatisfied = []
    very_unsatisfied = []

    for row in data:

        if row[11] == "Very Satisfied":
            very_satisfied.append(row[3])

        elif row[11] == "Satisfied":
            satisfied.append(row[3])

        elif row[11] == "Neutral":
            neutral.append(row[3])

        elif row[11] == "Unsatisfied":
            unsatisfied.append(row[3])

        elif row[11] == "Very Unsatisfied":
            very_unsatisfied.append(row[3])

    result = {}

    if len(very_satisfied) > 0:
        result["Very Satisfied"] = calculate_list_average(very_satisfied)

    if len(satisfied) > 0:
        result["Satisfied"] = calculate_list_average(satisfied)

    if len("Neutral") > 0:
        result["Neutral"] = calculate_list_average(neutral)

    if len(unsatisfied) > 0:
        result["Unsatisfied"] = calculate_list_average(unsatisfied)

    if len(very_satisfied) > 0:
        result["Very Unsatisfied"] = calculate_list_average(very_unsatisfied)

    return result

def coding_energy_analysis(data):

    high_coding = []
    medium_coding = []
    low_coding = []

    for row in data:

        if row[12] == "High":
            high_coding.append(row[4])

        elif row[12] == "Medium":
            medium_coding.append(row[4])

        elif row[12] == "Low":
            low_coding.append(row[4])

    result = {}

    if len(high_coding) > 0: 
        result["High"] = calculate_list_average(high_coding)

    if len(medium_coding) > 0:
        result["Medium"] = calculate_list_average(medium_coding)

    if len(low_coding) > 0:
        result["Low"] = calculate_list_average(low_coding)

    return result