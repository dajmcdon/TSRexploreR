# TSS Analysis

Transcription Start Sites (TSSs) represent the first base to be transcribed by RNA Polymerase.
Most genes tend to have a heterogenous collection of TSSs as opposed to a single position.
This is interesting because choice of TSS can affect gene isoform, stability, and translational efficiency.
Furthermore, TSS choice has been implicated in develoment, homseostasis, and disease.

tsrexploreR has a series of analysis and plotting functions to allow deep exploration of TSSs.

## Preparing Data

This example will use a set of *S. cerevisiae* TSSs collected using the STRIPE-seq method.
There are many ways to import TSSs into tsrexplorer.
This example data uses a named list of GRanges as imput into the function that creates the *tsrexplorer object*.

```
library("tsrexplorer")

TSSs <- system.file("extdata", "S288C_TSSs.RDS", package = "tsrexplorer")
TSSs <- readRDS(TSSs)

exp <- tsr_explorer(TSSs)
```

## Processing of TSSs

After the TSSs are loaded into the *tsrexplorer object*,
there are a few processing steps to go through to get the data ready for analysis.
These steps include converting the TSSs into a *RangedSummarizedExperiment*,
CPM normalizing the TSSs, and then marking the dominant TSS.

### TSS Data Structure

The first step is to convert the TSSs into a *RangedSummarizedExperiment*.
This object type is a convenient container that stores range, count, and sample information.

```
exp <- format_counts(exp, data_type = "tss")
```

### CPM Normalization

The next step is to Counts Per Million (CPM) normalize the TSSs and store them as an additional assay with the original counts.
This step is optional, and if the counts you inputed were normalized already this step can safely be skipped.

```
exp <- cpm_normalize(exp, data_type = "tss")
```

### Annotating TSSs

After formatting the counts and optionally CPM normalizing them, the TSSs will be annotated relative to known features.
This function takes either the path and file name of a *.GTF* or *.GFF* file, or a *BSgenome* package from bioconductor.
The annotation information will be added onto the range of the *RangedSummarizedExperiment*.
The example below uses a *GTF* file from Ensembl (R64-1-1 Release 99),
and will annotate each TSS to the closest transcript.

```
annotation <- system.file("extdata", "S288C_Annotation.gtf", package = "tsrexplorer")

exp <- annotate_features(
        exp, annotation_data = annotation,
        data_type = "tss", feature_type = "transcript"
)
```

### Feature Counting

Now that the TSSs are annotated relative to known features, an RNA-seq like summary of counts per feature can be generated.
TSSs that are upstream of the defined promoter region, or downstream of the last exon are ignored.
The feature counts can also be optionally CPM normalized as well.

```
exp <- count_features(exp)
exp <- cpm_normalize(exp, data_type = "features")
```

### Annotating Dominant TSSs

For the last processing step, the TSS with the highest score is marked for each feature.
Similar to the feature counting step above, TSSs that are upstream of the defined promoter region,
or downstream of the last exon are ignored.
If there are multiple TSSs with the same max score, all of those TSSs are considered.

It is sometimes interesting to look at dominant TSSs because this subset likely represents
the subset of genomic features (such as sequence) that are most preferred when the RNA Polymerase is choosing a TSS.
It thus is sometimes easier to resolve important features when looking at only the dominant TSSs.

```
exp <- dominant_tss(exp, threshold = 3)
```