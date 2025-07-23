# Football Scout

A C++ application that analyzes real-world football player data to identify undervalued players using statistical analysis and data science techniques. The system processes player performance metrics and market values to calculate performance scores and undervaluation ratings.

## Overview

The Football Scout application uses data-driven analysis to help scouts, analysts, and football enthusiasts discover hidden gems in the transfer market. By processing comprehensive player statistics and applying normalized scoring algorithms, it identifies players who deliver exceptional performance relative to their market value.

## Key Features

### Data Analysis & Processing
- **CSV Data Import**: Processes comprehensive player datasets including performance metrics, market values, and demographic information
- **Feature Engineering**: Normalizes player statistics using min-max scaling for fair comparisons across different metrics
- **Position-Specific Analysis**: Applies different weighting systems for defenders, midfielders, and forwards

### Scoring System
- **Performance Scoring**: Calculates comprehensive performance scores based on position-specific metrics
- **Undervaluation Analysis**: Identifies players whose performance exceeds their market value
- **Percentile Rankings**: Provides percentile rankings for all key performance indicators

### Interactive Features
- **Single Player Analysis**: Analyze individual players with detailed statistical breakdowns
- **Dataset Processing**: Batch analysis of entire player databases
- **Report Generation**: Comprehensive reports with detailed player evaluations

## Architecture

The application follows a modular architecture with clear separation of concerns:

### Core Components

#### FootballScout (Main Controller)
- Manages the main application flow and user interface
- Coordinates between different modules
- Handles user input and menu navigation

#### Player (Data Model)
- Represents individual player entities with comprehensive attributes
- Stores raw statistics: goals, assists, age, market value, position
- Maintains normalized values and percentile rankings
- Supports both offensive and defensive metrics

#### CsvParser (Data Input)
- Handles parsing of CSV football data files
- Converts raw data into Player objects
- Validates data integrity and handles missing values

#### FeatureEngineer (Data Processing)
- Implements min-max normalization for numerical features
- Calculates statistical distributions across the dataset
- Ensures fair comparison between players with different scales of performance

#### ScoringEngine (Analytics Core)
- Calculates percentile rankings for all player attributes
- Implements position-specific scoring algorithms
- Generates performance and undervaluation scores
- Supports weighted scoring based on player positions

#### ReportGenerator (Output)
- Creates detailed analytical reports
- Formats statistical data for easy interpretation
- Provides insights on player valuations and recommendations

#### PlayerInput (User Interface)
- Handles manual player data entry
- Validates user input
- Provides interactive data collection interface

## Data Model

The system processes the following player attributes:

### Basic Information
- **Player ID**: Unique identifier
- **Name**: Player's full name
- **Age**: Current age
- **Position**: DEFENDER, MIDFIELDER, FORWARD, or UNKNOWN
- **Market Value**: Current market valuation

### Performance Metrics
- **Goals**: Total goals scored
- **Assists**: Total assists provided
- **Goals per 90**: Goals scored per 90 minutes played
- **Assists per 90**: Assists provided per 90 minutes played
- **Goal Contributions per 90**: Combined goals and assists per 90 minutes

### Calculated Values
- **Performance Score**: Weighted score based on position-specific metrics
- **Undervaluation Score**: Ratio of performance to market value
- **Percentile Rankings**: Position within the dataset for each metric

## Getting Started

### Prerequisites
- C++ compiler with C++11 support or higher
- CMake 3.15 or higher
- Git (for cloning the repository)

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/Dennis-Gega/football_scout.git
   cd football_scout
2. **Build and run the program**
   ```bash
   mkdir build
   cd build
   cmake .
   cmake --build .
   ./football_scout
