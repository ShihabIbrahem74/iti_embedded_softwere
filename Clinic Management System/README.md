# Patient Appointment Scheduling System

A patient appointment scheduling system that enables administrators and users to manage appointments and patient records.

## Table of Contents

- [Description](#description)
- [Setup](#setup)
- [Usage](#usage)
  - [Admin Mode](#admin-mode)
  - [User Mode](#user-mode)
- [Features](#features)
- [Code Files](#code-files)
- [Contributors](#contributors)
- [License](#license)

## Description

This project implements a patient appointment scheduling system that offers two distinct modes of operation: Admin Mode, which provides administrators with various features to manage the system, and User Mode, which allows regular users to interact with the system for appointment reservations and modifications.

## Setup

Follow these steps to set up and use the system:

1. Clone the repository to your local machine.
2. Compile the `main.c` file using a C compiler.
3. Run the compiled executable.

## Usage

### Admin Mode

- Log in using the admin password.
- Choose from a range of features for system management, including:
  - Adding new patient records.
  - Editing patient information.
  - Booking and canceling appointment slots.
  - Viewing all patient records and appointments.

### User Mode

- Display your record and reservations.
- Sign up as a new user.
- Browse available slots and reserve appointments.
- Modify your existing reservations.
- Cancel appointments.

## Features

- Admin and user modes with distinct levels of access.
- Patient record management including name, age, gender, and ID.
- Appointment slot management with day, time, and ID.
- Booking, modifying, and canceling appointments.
- User-friendly interface for ease of use.

## Code Files

- `main.c`: Main program handling mode selection and function calls.
- `main.h`: Header file with structure definitions and function prototypes.
- `mode_picker.c`: Implementation of the `choose_mode` function for mode selection.
- `admin.c`: Functions for admin-specific tasks like login and feature selection.
- `user.c`: Functions for user-specific actions, sign-up, reservation, and editing.
- `admin_features.c`: Implementation of admin-specific features, such as patient record management and appointment booking.
- `user_feature.c`: Implementation of user-specific features, including showing user information and appointment reservations.

## Contributors

- [Shihab Ibrahem](https://github.com/ShihabIbrahem74) - Main Developer

## License

This project is licensed under the [ITI License](LICENSE).
