from fastapi import FastAPI
from pydantic import BaseModel

app = FastAPI()


class Patient(BaseModel):
    fio: str
    disease: str


patients = [
    {"fio": "Петр Петров Петрович", "disease": "Слишком прямой нос"},
    {"fio": "Иванов Иван Иванович", "disease": "Отсутствие осознанности"},
]

@app.post("/patients/")
async def add_patient(new_patient: Patient):
    patients.append(dict(new_patient))
    return patients


@app.get("/patients/")
async def get_patients():
    return patients
