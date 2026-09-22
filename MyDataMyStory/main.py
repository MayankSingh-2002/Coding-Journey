import RoutineExcel

filename = "12612197.xlsx"

data = RoutineExcel.read_data(filename)

valid_data, invalid_records = RoutineExcel.validate_data(data)

print("\nRecorded Dates:")

for row in valid_data:
    print(row[0])

print("Total records:", len(data))
print("Valid records:", len(valid_data))
print("Invalid records:", invalid_records)

expected_days, missing_days = RoutineExcel.check_continue_date(valid_data)

averages = RoutineExcel.calculate_activity_averages(valid_data)

activity_indices = RoutineExcel.calculate_activity_indices(valid_data)

experience_index = RoutineExcel.caluclate_experience_index(valid_data)

DCI = RoutineExcel.calculate_dci(len(valid_data), expected_days)

PAI = RoutineExcel.calculate_pai(activity_indices,experience_index, DCI)

sleep_energy = RoutineExcel.sleep_energy_analysis(valid_data)

study_satisfaction = RoutineExcel.study_satisafaction_analysis(valid_data)

coding_energy = RoutineExcel.coding_energy_analysis(valid_data)


print("MY DATA MY STORY")

print("=======================")

print("Expected Days: ", expected_days)
print("Valid Days: ", len(valid_data))
print("Missing Days: ", len(missing_days))
print("Invalid Records: ", invalid_records)

print("\nActivity Averages:-")

print("Sleep: ", averages["sleep"])
print("Fitness: ", averages["fitness"])
print("Study: ", averages["study"])
print("Coding: ", averages["coding"])
print("Class: ", averages["class"])
print("Other Activities: ", averages["other"])
print("Total Tracked: ",averages["total_tracked"])
print("Free/Unaccounted: ", averages["free_time"])

print("\nIndices")

print("TPI: ",activity_indices["TPI"])
print("AAI: ",activity_indices["AAI"])
print("PhAI: ",activity_indices["PhAI"])
print("SRI: ",activity_indices["SRI"])
print("ABI: ",activity_indices["ABI"])
print("TUI: ",activity_indices["TPI"])
print("EI: ",experience_index)
print("DCI: ", DCI)
print("PAI: ", PAI)

print("\nSleep and Energy")
print(sleep_energy)
print("\nStudy and Satisfaction")
print(study_satisfaction)
print("\nCoding and Energy")
print(coding_energy)