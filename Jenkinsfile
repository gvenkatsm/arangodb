//  -*- mode: groovy-mode

pipeline {
    agent any 

    stages {
        stage('GIT CC') {
            steps { 
                node('master') {
                    milestone(1)

                    checkout scm
                    stash includes: '**', name: 'source'
                }
            }
        }

        stage('Build CC LX') { 
            steps { 
                node('linux') {
                    milestone(2)

                    unstash 'source'

                    sh 'pwd'
                    sh 'ls -la'
                    sh './Installation/Pipeline/build_cc_lx.sh 16'

                    stash includes: 'build/** js/** etc/**', name: 'build-cc-lx'
                }
            }
        }
    }
}
