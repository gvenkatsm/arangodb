//  -*- mode: groovy-mode

pipeline {
    agent any 

    stages {
        stage('GIT CC') {
            steps { 
                node('master') {
                    milestone(1)

                    checkout scm

                    sh 'pwd'
                    sh 'ls -la'

                    stash includes: '**', name: 'source'
                }
            }
        }

        stage('Build CC LX') { 
            steps { 
                node('linux') {
                    milestone(2)

                    unstash 'source'

                    sh './Installation/Pipeline/build_cc_lx.sh 16'

                    stash includes: 'build/**,js/**,etc/**', name: 'build-cc-lx'

                    sh 'pwd'
                    sh 'ls -la'
                }
            }
        }
    }
}
